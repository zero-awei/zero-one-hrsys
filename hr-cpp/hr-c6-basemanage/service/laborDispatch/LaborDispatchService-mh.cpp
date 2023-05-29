/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:08:20

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
#include "LaborDispatchService-mh.h"
#include "domain/do/laborDispatch/LaborDispatchDO.h"
#include "dao/laborDispatch/LaborDispatchDAO-mh.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "../hr-sample/Macros.h"
#include "FastDfsClient.h"

#define DO_TO_VECTOR(f) \
ss.clear(); \
ss << sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");


LaborDispatchPageDTO::Wrapper LaborDispatchService::listAll_ld(const LaborDispatchQuery::Wrapper& query)
{
	//构建返回对象
	auto pages = LaborDispatchPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//查询数据总条数
	LaborDispatchDAO dao;
	uint64_t count = dao.count_ld(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页插叙数据
	pages->total = count;
	pages->calcPages();
	list<LaborDispatchDO> result = dao.selectWrithPage_Query(query);
	//将DO转换成DTO
	for (LaborDispatchDO sub : result)
	{
		auto dto = LaborDispatchDTO::createShared();
		dto->enable = sub.get_Enable();
		dto->name = sub.getName();
		dto->id = sub.getId();
		dto->createdate = sub.getCreatedate();
		dto->createman = sub.getCreateman();
		dto->updateman = sub.getUpdateman();
		dto->updatedate = sub.getUpdatedate();
		dto->jyfw = sub.getJyfw();
		dto->lxdz = sub.getLxdz();
		dto->lxfs = sub.getLxfs();
		dto->lxr = sub.getLxr();
		dto->gsjj = sub.getGsjj();
		dto->pimpersonid = sub.getPimpersonid();
		dto->ormorgid = sub.getOrmorgid();
		dto->legalperson = sub.getLegalperson();
		dto->regcapital = sub.getRegcapital();
		pages->addData(dto);
	}
	return pages;
}

uint64_t LaborDispatchService::saveData_ld(const LaborDispatchDTO::Wrapper& dto)
{
	//组装DO数据
	LaborDispatchDO data;
	data.set_Enable(dto->enable.getValue(""));
	data.setName(dto->name.getValue(""));
	data.setId(dto->id.getValue(""));
	data.setCreatedate(dto->createdate.getValue(""));
	data.setCreateman(dto->createman.getValue(""));
	data.setUpdateman(dto->updateman.getValue(""));
	data.setUpdatedate(dto->updatedate.getValue(""));
	data.setJyfw(dto->jyfw.getValue(""));
	data.setLxdz(dto->lxdz.getValue(""));
	data.setLxfs(dto->lxfs.getValue(""));
	data.setLxr(dto->lxdz.getValue(""));
	data.setGsjj(dto->gsjj.getValue(""));
	data.setPimpersonid(dto->pimpersonid.getValue(""));
	data.setOrmorgid(dto->ormorgid.getValue(""));
	data.setRegcapital(dto->regcapital.getValue(""));
	data.setLegalperson(dto->legalperson.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _Enable, enable, Name, name, Id, id, Createdate, createdate, Createman, createman, Updateman, updateman, Updatedate, updatedate, Jyfw, jyfw, Lxdz, lxdz, Lxr, lxr, Lxfs, lxfs, Gsjj, gsjj, Pimpersonid, pimpersonid, Ormorgid, ormorgid, Regcapital, regcapital, Legalperson, legalperson)
		//执行数据添加
		LaborDispatchDAO dao;
	return dao.insert_ld(data);
}

bool LaborDispatchService::removeData_ld(string id)
{
	LaborDispatchDAO dao;
	return dao.deleteById_ld(id) == 1;
}

std::string LaborDispatchService::LaborDispatchExport_ld(const LaborDispatchQuery::Wrapper& query)
{
	vector<vector<string>> data;
	list<LaborDispatchDO> result = LaborDispatchDAO().selectWrithPage_Export(query);
	data.push_back({
		"ENABLE",
		ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME"),
		ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYID"),
		ZH_WORDS_GETTER("ldcompany.field.CREATEDATE"),
		ZH_WORDS_GETTER("ldcompany.field.CREATEMAN"),
		ZH_WORDS_GETTER("ldcompany.field.UPDATEMAN"),
		ZH_WORDS_GETTER("ldcompany.field.UPDATEDATE"),
		ZH_WORDS_GETTER("ldcompany.field.JYFW"),
		ZH_WORDS_GETTER("ldcompany.field.LXDZ"),
		ZH_WORDS_GETTER("ldcompany.field.LXFS"),
		ZH_WORDS_GETTER("ldcompany.field.LXR"),
		ZH_WORDS_GETTER("ldcompany.field.GSJJ"),
		ZH_WORDS_GETTER("ldcompany.field.PIMPERSONID"),
		ZH_WORDS_GETTER("ldcompany.field.ORMORGID"),
		ZH_WORDS_GETTER("ldcompany.field.REGCAPITAL"),
		ZH_WORDS_GETTER("ldcompany.field.LEGALPEROSN")
		});
	stringstream ss;
	for (LaborDispatchDO sub : result) {
		vector<string> row;
		DO_TO_VECTOR(_Enable);
		DO_TO_VECTOR(Name);
		DO_TO_VECTOR(Id);
		DO_TO_VECTOR(Createdate);
		DO_TO_VECTOR(Createman);
		DO_TO_VECTOR(Updateman);
		DO_TO_VECTOR(Updatedate);
		DO_TO_VECTOR(Jyfw);
		DO_TO_VECTOR(Lxdz);
		DO_TO_VECTOR(Lxfs);
		DO_TO_VECTOR(Lxr);
		DO_TO_VECTOR(Gsjj);
		DO_TO_VECTOR(Pimpersonid);
		DO_TO_VECTOR(Ormorgid);
		DO_TO_VECTOR(Regcapital);
		DO_TO_VECTOR(Legalperson);
		data.push_back(row);
	}
	ss << "./tmp/excel" << chrono::system_clock::now().time_since_epoch().count() << ".xlsx";
	string fileName = ss.str();
	string sheetName = CharsetConvertHepler::ansiToUtf8("sheet1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif // LINUX
	//上传excel结果
	string filedName = client.uploadFile(fileName);
	//删除产生的临时文件
	remove(fileName.c_str());
	//返回下载路径
	string filepath = filedName;
	return filepath;
}
