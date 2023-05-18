#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 8:59:52

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
#ifndef _WORKHISTORYFINDPAGEDO_H_
#define _WORKHISTORYFINDPAGEDO_H_


#include "../DoInclude.h"

class WorkHIstoryFindDO
{
	//任职开始时间
	CC_SYNTHESIZE(std::string, RZKSSJ, rZKSSJ);

	//任职结束时间
	CC_SYNTHESIZE(std::string, RZJSSJ, rZJSSJ);

	//工作单位
	CC_SYNTHESIZE(std::string, ORMORGNAME, oRMORGNAME);

	//部门
	CC_SYNTHESIZE(std::string, BM, bM);

	//职位
	CC_SYNTHESIZE(std::string, ZW, zW);

	//岗位
	CC_SYNTHESIZE(std::string, GW, gW);

	//兼职借调类型
	CC_SYNTHESIZE(std::string, CFPLX, cFPLX);

	//是否主要经历
	CC_SYNTHESIZE(std::string, EXPERIENCE, eXPERIENCE);



};

#endif // !_WORKHISTORYFINDPAGEDO_H_