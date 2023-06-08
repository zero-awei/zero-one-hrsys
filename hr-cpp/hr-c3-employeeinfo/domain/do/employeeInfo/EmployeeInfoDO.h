#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/23 19:17:19

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
#ifndef _EMPLOYEEINFODO_H_
#define _EMPLOYEEINFODO_H_
#include "../DoInclude.h"
/* *
* 员工信息DO
* 执行人：Detachment
*/
class EmployeeInfoDO
{
	CC_SYNTHESIZE(string, id, Id)
	CC_SYNTHESIZE(string, name, Name)
	CC_SYNTHESIZE(string, idType, IdType)
	CC_SYNTHESIZE(string, idNum, IdNum)
	CC_SYNTHESIZE(string, birthday, Birthday)
	CC_SYNTHESIZE(int, age, Age)
	CC_SYNTHESIZE(string, sex, Sex)
	CC_SYNTHESIZE(string, blood, Blood)
	CC_SYNTHESIZE(string, phone, Phone)
	CC_SYNTHESIZE(string, email, Email)
	CC_SYNTHESIZE(string, marriage, Marriage)
	CC_SYNTHESIZE(string, nation, Nation)
	CC_SYNTHESIZE(string, residentType, ResidentType)
	CC_SYNTHESIZE(string, native, Native)
	CC_SYNTHESIZE(string, residentPlace, ResidentPlace)
	CC_SYNTHESIZE(string, residentLocate, ResidentLocate)
	CC_SYNTHESIZE(string, birthPlace, BirthPlace)
	CC_SYNTHESIZE(string, comePlace, ComePlace)
	CC_SYNTHESIZE(string, onlyCredit, OnlyCredit)
	CC_SYNTHESIZE(string, hobby, Hobby)
	CC_SYNTHESIZE(string, health, Health)
	CC_SYNTHESIZE(string, politic, Politic)
	CC_SYNTHESIZE(string, estate, eState)
	CC_SYNTHESIZE(string, workState, WorkState)
	CC_SYNTHESIZE(string, inWay, InWay)
	CC_SYNTHESIZE(string, workTime, WorkTime)
	CC_SYNTHESIZE(string, inTime, InTime)
	CC_SYNTHESIZE(string, photo, Photo)
	CC_SYNTHESIZE(string, rank, Rank)
	CC_SYNTHESIZE(string, techtitle, TechTitle)
	CC_SYNTHESIZE(string, acaCredit, AcaCredit)
	CC_SYNTHESIZE(string, friAcaCredit, FirAcaCredit)
    CC_SYNTHESIZE(string, pracCerfigicate,PracCerfigicate)

public:
	EmployeeInfoDO() {
		rank = "";
		techtitle = "";
		acaCredit = "";
		friAcaCredit = "";
		pracCerfigicate = "";
		id = "";
		name = "";
		idType = "";
		idNum = "";
		birthday = "";
		age = 0;
		sex = "";
		blood = "";
		phone = "";
		email = "";
		marriage = "";
		nation = "";
		residentType = "";
		native = "";
		residentPlace = "";
		residentLocate = "";
		birthPlace = "";
		comePlace = "";
		onlyCredit = "";
		hobby = "";
		health = "";
		politic = "";
		estate = "";
		workState = "";
		inWay = "";
		workTime = "";
		inTime = "";
		photo = "";
	}
};

#endif // !_EMPLOYEEINFODO_H_