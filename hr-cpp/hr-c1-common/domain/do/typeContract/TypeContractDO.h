#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/22 0:08:37

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
#ifndef _HTLX_DO_
#define _HTLX_DO_
#include "../DoInclude.h"

class HtlxDO
{
	//建立时间
	CC_SYNTHESIZE(string, createdate, Createdate);
	//合同/协议类型管理标识
	CC_SYNTHESIZE(string, pimcontracttypeid,Pimcontracttypeid);
	//合同类别名称
	CC_SYNTHESIZE(string, pimcontracttypename, Pimcontracttypename);
	//建立人
	CC_SYNTHESIZE(string, createman, Createman);
	//更新人
	CC_SYNTHESIZE(string,  updateman, Updateman);
	//更新时间
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	//合同类别代码
	CC_SYNTHESIZE(string, sbm, Sbm);
	//类型
	CC_SYNTHESIZE(string, lx, Lx);
	//组织标识
	CC_SYNTHESIZE(string, ormorgid, Ormorgid);
public:
	HtlxDO() {
		createdate = "";
		pimcontracttypeid = "";
		pimcontracttypename = "";
		createman = "";
		updateman = "";
		updatedate = "";
		sbm = "";
		lx = "";
		ormorgid = "";
	}
};

#endif // !_HTLX_DO_

