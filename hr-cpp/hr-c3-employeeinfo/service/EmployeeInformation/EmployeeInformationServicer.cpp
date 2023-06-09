/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 15:38:37

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "EmployeeInformationServicer.h"
#include "dao/EmployeeInformation/EmployeeInformationDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "CustomerAuthorizeHandler.h"
#include "ExcelComponent.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"
#include "uselib/excel/ExportExcel.h"
#include <uselib/fastdfs/UseFastDfs.h>

// 文件到DO宏
#define FILE_TO_DO(target, src, f1, f2) target.set##f1(src.f2);
#define INDEX(x, y) at(x).at(y)
#define ZO_STAR_FILE_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, FILE_TO_DO, __VA_ARGS__))

// 分页查询所有数据
EmployeeInformationPageDTO::Wrapper EmployeeInformationServicer::listAll(const EmployeeInformationPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = EmployeeInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	EmployeeInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<EmployeeInformationPageDO> result = dao.selectWithPage(query);
	
	// 将DO转换成DTO
	for (EmployeeInformationPageDO sub : result)
	{
		auto dto = EmployeeInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, age, Age, id, Id, \
	    organize, Organize, depart, Depart, job, Job, post, Post, idMum, IdMum,\
		birthday, Birthday, phone, Phone, state, State);
		pages->addData(dto);

	}
	return pages;
}
//新增员工信息
uint64_t EmployeeInformationServicer::saveData(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	EmployeeInformationPageDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CreateMan, createMan, CreateDate, createDate,\
	Name, name, Age, age, Id, id, Organize, organize, Depart, depart,\
		Job, job, Post, post, IdMum, idMum, Birthday, birthday, Phone, phone,\
		State, state);

	// 生成主键
	SnowFlake sf(1, 3);//雪花算法
	data.setPersonId(to_string(sf.nextId()));
	//建立人
	data.setCreateMan(payload.getId());
	//建立时间
	SimpleDateTimeFormat sdtf;//获取当前时间格式字符串
	data.setCreateDate(sdtf.format());

	// 需要再服务器生成的数据
	data.setName(dto->name);
	data.setAge(dto->age);
	data.setId(dto->id);
	data.setOrganize(dto->organize);
	data.setDepart(dto->depart);
	data.setJob(dto->job);
	data.setPost(dto->post);
	data.setIdMum(dto->idMum);
	data.setBirthday(dto->birthday);
	data.setPhone(dto->phone);
	data.setState(dto->state);
	// 执行数据添加
	EmployeeInformationDAO dao;
	return dao.insert(data);
}
//导入员工信息(批量新增)
importInfoVO::Wrapper EmployeeInformationServicer::addMultiEmployee(const ImportInfoDTO::Wrapper& dto, const PayloadDTO& payload) {

	// 构建Excel对象
	ExcelComponent excel;
	// 将文件数据读取出来
	auto data = excel.readIntoVector(std::string(dto->filePath), std::string(dto->sheetName));

	// 构建字段坐标映射
	unordered_map<string, int> hash;
	for (int i = 0; i < static_cast<int>(data[0].size()); i++)
	{
		hash[data[0][i]] = i;
	}

	// 生成SnowFlake对象
	SnowFlake sf(1, 3);//雪花算法
	string name = payload.getId();
	string day = SimpleDateTimeFormat::format();//获取当前时间格式字符串
	// 文件数据到DO
	list<EmployeeInformationPageDO> all;
	for (int i = 1; i < static_cast<int>(data.size()); i++)
	{
		EmployeeInformationPageDO tmp;
		ZO_STAR_FILE_TO_DO(tmp, data,
			Name,INDEX(i,hash["NAME"]),
			Id,INDEX(i,hash["ID"]),
			Organize,INDEX(i,hash["ORGANIZE"]),
			Depart,INDEX(i,hash["DEPART"]),
			Job,INDEX(i,hash["JOB"]),
			Post,INDEX(i,hash["POST"]),
			IdMum,INDEX(i,hash["IDMUN"]),
			Birthday,INDEX(i,hash["BIRTHDAY"]),
			Phone,INDEX(i,hash["PHONE"]),
			State,INDEX(i,hash["STATE"])
		);
		//年龄
		tmp.setAge(atoi(data[i][hash["AGE"]].c_str()));
		//生成主键
		tmp.setPersonId(to_string(sf.nextId()));
		//建立人
		tmp.setCreateMan(name);
		//建立时间
		tmp.setCreateDate(day);
		all.push_back(tmp);
	}

	// 调用DAO操作数据库
	EmployeeInformationDAO dao;
	SqlSession* ss = dao.getSqlSession();
	// 开启事务处理
	ss->beginTransaction();

	std::list<std::string> res;
	for (auto item : all)
	{
		long long line = dao.insert(item);
		// 新增成功则加入一个新的id
		if (line == 1)
		{
			res.push_back(item.getPersonId());
		}
		// 否则清空新增id返回列表并回滚
		else
		{
			ss->rollbackTransaction();
			res.clear();
			break;
		}
	}

	// 提交事务
	ss->commitTransaction();

	// 构建返回对象
	auto vo = importInfoVO::createShared();
	if (res.size())
	{
		for (auto item : res)
			vo->newId->push_back(item);
	}

	return vo;
}
//导出员工信息(导出本页在前端完成)
std::string EmployeeInformationServicer::exportEmpInfomation(const PostDetailQuery::Wrapper& query)
{
	EmployeeInformationDAO dao;
	auto res = dao.exportEmpInfo(query);

	ExportExcel excel;

	vector<vector<string>> data;
	for (auto item : res)
	{
		vector<string> tmp;
		tmp.push_back(item.getName());
		tmp.push_back(to_string(item.getAge()));
		tmp.push_back(item.getId());
		tmp.push_back(item.getOrganize());
		tmp.push_back(item.getDepart());
		tmp.push_back(item.getJob());
		tmp.push_back(item.getPost());
		tmp.push_back(item.getIdMum());
		tmp.push_back(item.getBirthday());
		tmp.push_back(item.getPhone());
		tmp.push_back(item.getState());
		data.push_back(tmp);
	}

	// 生成数据表表头
	vector<string> head = dao.getEmpInfoHead();

	// 导出到Excel文件
	data.insert(data.begin(), head);
	string fileName = excel.exportExcel(data);

	// TODO: 上传到FastDFS文件服务器, 返回下载链接
	UseFastDfs dfs;
	string url = dfs.uploadWithNacos(fileName);

	return url;
}
