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
		//// 姓名
		//dto->name = sub.getName();
		//// 年龄
		//dto->age = sub.getAge();
		////编号
		//dto->id = sub.getId();
		////组织
		//dto->organize = sub.getOrganize();
		////部门
		//dto->depart = sub.getDepart();
		////职务
		//dto->job = sub.getJob();
		////岗位
		//dto->post = sub.getPost();
		////证件号
		//dto->idMum = sub.getIdMum();
		////出生日期
		//dto->birthday = sub.getBirthday();
		////手机号码
		//dto->phone = sub.getPhone();
		////员工状态
		//dto->state = sub.getState();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, age, Age, id, Id, organize, Organize, depart, Depart, job, Job, post, Post, idMum, IdMum, birthday, Birthday, phone, Phone, state, State);
		pages->addData(dto);

	}
	return pages;
}
//新增员工信息
uint64_t EmployeeInformationServicer::saveData(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	EmployeeInformationPageDO data;
	//// 姓名
	//data.setName(dto->name.getValue(""));
	//// 年龄
	//data.setAge(dto->age.getValue(1));
	////编号
	//data.setId(dto->id.getValue(""));
	////组织
	//data.setOrganize(dto->organize.getValue(""));
	////部门
	//data.setDepart(dto->depart.getValue(""));
	////职务
	//data.setJob(dto->job.getValue(""));
	////岗位
	//data.setPost(dto->post.getValue(""));
	////证件号
	//data.setIdMum(dto->idMum.getValue(""));
	////出生日期
	//data.setBirthday(dto->birthday.getValue(""));
	////手机号码
	//data.setPhone(dto->phone.getValue(""));
	////员工状态
	//data.setState(dto->state.getValue(""));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CreateMan, createMan, CreateDate, createDate,\
	Name, name, Age, age, Id, id, Organize, organize, Depart, depart, Job, job, Post, post, IdMum, idMum, Birthday, birthday, Phone, phone, State, state);

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

