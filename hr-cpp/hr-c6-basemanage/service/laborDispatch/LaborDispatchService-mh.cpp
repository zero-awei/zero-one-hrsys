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
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->unit = sub.getUnit();
		dto->lxdz = sub.getLxdz();
		dto->lxfs = sub.getLxfs();
		dto->lxr = sub.getLxr();
		dto->legalperson = sub.getLegalperson();
		dto->regcapital = sub.getRegcapital();
		dto->updatedate = sub.getUpdatedate();
		pages->addData(dto);
	}
	return pages;
}

uint64_t LaborDispatchService::saveData_ld(const LaborDispatchModifyDTO::Wrapper& dto)
{
	//组装DO数据
	LaborDispatchDO data;
	data.setName(dto->name.getValue(""));
	data.setUnit(dto->unit.getValue(""));
	data.setLxdz(dto->lxdz.getValue(""));
	data.setLxr(dto->lxdz.getValue(""));
	data.setLxfs(dto->lxfs.getValue(""));
	data.setLegalperson(dto->legalperson.getValue(""));
	data.setRegcapital(dto->regcapital.getValue(""));
	data.setGsjj(dto->gsjj.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Name, name, Unit, unit, Lxdz, lxdz, Lxr, lxr, Lxfs, lxfs, Legalperson, legalperson, Regcapital, regcapital, Gsjj, gsjj)
	//执行数据添加
	LaborDispatchDAO dao;
	return dao.insert_ld(data);
}

bool LaborDispatchService::removeData_ld(string id)
{
	LaborDispatchDAO dao;
	return dao.deleteById_ld(id) == 1;
}

std::string LaborDispatchService::LaborDispatchExport_ld(const LaborDispatchQuery::Wrapper& query, const LaborDispatchExportDTO::Wrapper& dto)
{
	vector<vector<string>> data;
	LaborDispatchDAO dao;
	list<LaborDispatchDO> result =dao.selectWrithPage_Export(query);
	auto flag = dto->ziduan->begin();
	vector<string> row1;
	while (flag != dto->ziduan->end()) {
		if (flag->getValue("") == "PIMLABOURCAMPANYNAME") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME"));
		}
		else if (flag->getValue("") == "ORGNAME") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.ORGNAME"));
		}
		else if (flag->getValue("") == "LXDZ") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.LXDZ"));
		}
		else if (flag->getValue("") == "LXR") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.LXR"));
		}
		else if (flag->getValue("") == "LXFS") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.LXFS"));
		}
		else if (flag->getValue("") == "REGCAPITAL") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.REGCAPITAL"));
		}
		else if (flag->getValue("") == "LEGALPEROSN") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.LEGALPEROSN"));
		}
		else if (flag->getValue("") == "UPDATEDATE") {
			row1.push_back(ZH_WORDS_GETTER("ldcompany.field.UPDATEDATE"));
		}
		flag++;
	}
	data.push_back(row1);
	stringstream ss;
	
	for (LaborDispatchDO sub : result) {
		auto flag = dto->ziduan->begin();
		vector<string> row;
		while (flag != dto->ziduan->end())
		{
			if (flag->getValue("") == "PIMLABOURCAMPANYNAME") {
				DO_TO_VECTOR(Name);
				flag++;
			}
			else if (flag->getValue("") == "ORGNAME") {
				DO_TO_VECTOR(Unit);
				flag++;
			}
			else if (flag->getValue("") == "LXDZ") {
				DO_TO_VECTOR(Lxdz);
				flag++;
			}
			else if (flag->getValue("") == "LXR") {
				DO_TO_VECTOR(Lxr);
				flag++;
			}
			else if (flag->getValue("") == "LXFS") {
				DO_TO_VECTOR(Lxfs);
				flag++;
			}
			else if (flag->getValue("") == "REGCAPITAL") {
				DO_TO_VECTOR(Regcapital);
				flag++;
			}
			else if (flag->getValue("") == "LEGALPEROSN") {
				DO_TO_VECTOR(Legalperson);
				flag++;
			}
			else if (flag->getValue("") == "UPDATEDATE") {
				DO_TO_VECTOR(Updatedate);
				flag++;
			}
		}
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
	string filepath = "8.130.87.15:8888/" + filedName;
	return filepath;
}
