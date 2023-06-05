#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _SCIRESULT_DO_
#define _SCIRESULT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class SciResultDO
{
	    //更新人
	CC_SYNTHESIZE(string, UPDATEMAN, _UPDATEMAN);

		//科研成果名称
	CC_SYNTHESIZE(string, PIMRESEARCHFINDINGSNAME, _PIMRESEARCHFINDINGSNAME);
		//附件
	CC_SYNTHESIZE(string, FJ, _FJ);
		//ENABLE
	CC_SYNTHESIZE(string, ENABLE, _ENABLE);
		//建立时间
	CC_SYNTHESIZE(string, CREATEDATE, _CREATEDATE);
		//更新时间
	CC_SYNTHESIZE(string, UPDATEDATE, _UPDATEDATE);
		//建立人
	CC_SYNTHESIZE(string, CREATEMAN, _CREATEMAN);
		//科研成果标识
	CC_SYNTHESIZE(string, PIMRESEARCHFINDINGSID, _PIMRESEARCHFINDINGSID);
		//人员信息标识
	CC_SYNTHESIZE(string, PIMPERSONID, _PIMPERSONID);
		//获取时间
	CC_SYNTHESIZE(string, HQSJ, _HQSJ);
		//记录所属
	CC_SYNTHESIZE(string, JLSS, _JLSS);
		//审批状态
	CC_SYNTHESIZE(string, JLSPZT, _JLSPZT);
		//记录管理编号
	CC_SYNTHESIZE(string, JLGLBH, _JLGLBH);
		//记录操作者
	CC_SYNTHESIZE(string, JLCZZ, _JLCZZ);
		//拒绝原因
	CC_SYNTHESIZE(string, REASON, _REASON); 
public:
	SciResultDO() = default;

	SciResultDO(std::vector<std::string> vec)
	{
		//修改
		int i = 0;
		set_PIMRESEARCHFINDINGSNAME(vec[i++]);
		set_HQSJ(vec[i++]);
		set_FJ(vec[i++]);
	}

};

#endif // !_SAMPLE_DO_
