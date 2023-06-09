#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/22 14:35:21

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
#ifndef _ADDWORKHISTORYDO_H_
#define _ADDWORKHISTORYDO_H_



class AddWorkHistoryDO
{
	//1任职开始时间
	CC_SYNTHESIZE(std::string, RZKSSJ, rZKSSJ);

	//2任职结束时间
	CC_SYNTHESIZE(std::string, RZJSSJ, rZJSSJ);

	//3工作单位
	CC_SYNTHESIZE(std::string, ORMORGNAME, oRMORGNAME);

	//4部门
	CC_SYNTHESIZE(std::string, ORMORGSECTORNAME, oRMORGSECTORNAME);

	//5职位
	CC_SYNTHESIZE(std::string, ORMDUTYNAME, oRMDUTYNAME);

	//6岗位
	CC_SYNTHESIZE(std::string, ORMPOSTNAME, oRMPOSTNAME);

	//7兼职借调类型
	CC_SYNTHESIZE(std::string, CFPLX, cFPLX);

	//8是否主要经历
	CC_SYNTHESIZE(uint64_t, EXPERIENCE, eXPERIENCE);

	//9工作履历独有id
	CC_SYNTHESIZE(std::string, PIMWORKHISTORYID, pIMWORKHISTORYID);

	//10人员信息id
	CC_SYNTHESIZE(std::string, PIMPERSONID, pIMPERSONID);

	//创建人
	CC_SYNTHESIZE(std::string, CREATEMAN, cREATEMAN);

	//更新人
	CC_SYNTHESIZE(std::string, UPDATEMAN, uPDATEMAN);

	//创建时间
	CC_SYNTHESIZE(std::string, CREATEDATE, cREATEDATE);

	//更新时间
	CC_SYNTHESIZE(std::string, UPDATEDATE, uPDATEDATE);

public:
	AddWorkHistoryDO() = default;

	AddWorkHistoryDO(std::vector<std::string> vec)
	{
		int i = 0;
		setrZKSSJ(vec[i++]);
		setrZJSSJ(vec[i++]);
		setoRMORGNAME(vec[i++]);
		setoRMORGSECTORNAME(vec[i++]);
		setoRMDUTYNAME(vec[i++]);
		setoRMPOSTNAME(vec[i++]);
		setcFPLX(vec[i++]);
		seteXPERIENCE(atoi(vec[i++].c_str()));
	}


};

#endif // !_ADDWORKHISTORYDO_H_