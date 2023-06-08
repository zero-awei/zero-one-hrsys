/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/25 8:14:09

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
#include "EmployeeInfoService.h"
#include "../../dao/employeeInfo/EmployeeInfoDAO.h"
#include "Macros.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

EmployeeInfoQuery::Wrapper EmployeeInfoService::listEmployee(const EmployeeInfoQuery::Wrapper& query)
{
	EmployeeInfoDAO dao;
	auto dto=EmployeeInfoQuery::createShared();
	list<EmployeeInfoDO> res = dao.selectEmployee(query);
	for (EmployeeInfoDO c : res)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, c, id, Id, name, Name, idType, IdType, idNum, IdNum,
			birthday, Birthday, age, Age, sex, Sex, phone, Phone, email,
			Email, marriage, Marriage, nation, Nation, native,
			Native,politic, Politic,workTime, WorkTime,inTime, InTime, photo, Photo);
	}
	return dto;
}

bool EmployeeInfoService::insertEmployee(const EmployeeInfoAddDTO::Wrapper& edto, const PayloadDTO& payLoad)
{
	/*EmployeeInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, edto, Id, empid, Name, name, IdType, idType, IdNum, idNum, Phone, phoneNum, eState, state);
	*/
	SimpleDateTimeFormat sdtf;
	string dt = sdtf.format();
	string pl = payLoad.getId();
	EmployeeInfoDAO dao;
	SnowFlake sf(1, 3);
	return dao.insertEmployee(edto, to_string(sf.nextId()),dt, pl);
}

bool EmployeeInfoService::updateEmployee(const EmployeeInfoDTO::Wrapper& edto, const PayloadDTO& payLoad)
{
	/*EmployeeInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, edto, Id, empid, Name, name, IdType, idtype, IdNum, idnum, Birthday,
		bthdate, Age, age, Sex, sex, Blood, blood, Phone, phone, Email, email, Marriage, marriage,
		Nation, nation, ResidentType, residentType, Native, native, ResidentPlace, residentPlace,
		ResidentLocate, residentLocate, BirthPlace, birthPlace, ComePlace, comPlace, OnlyCredit, onlyCredit,
		Hobby, hobby, Health, health, Politic, politic, WorkTime, workTime, InTime, inTime, Photo, photo);*/
	EmployeeInfoDAO dao;\
	string pl = payLoad.getId();
	return dao.updateEmployee(edto,pl);
}
