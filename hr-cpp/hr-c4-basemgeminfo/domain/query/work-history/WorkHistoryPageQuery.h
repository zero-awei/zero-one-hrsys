#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/14 16:45:02

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
#ifndef _WORKHISTORYPAGEQUERY_H_
#define _WORKHISTORYPAGEQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)



class WorkHistoryPageQuery : public PageQuery
{
	DTO_INIT(WorkHistoryPageQuery, PageQuery);
	

	//任职开始时间
	DTO_FIELD(String, servebegintime);
	DTO_FIELD_INFO(servebegintime) {
		info->description = ZH_WORDS_GETTER("workhistory.field.servebegintime");
	}


	//任职结束时间
	DTO_FIELD(String, serveendtime);
	DTO_FIELD_INFO(serveendtime) {
		info->description = ZH_WORDS_GETTER("workhistory.field.serveendtime");
	}

	//工作单位
	DTO_FIELD(String, workunit);
	DTO_FIELD_INFO(workunit) {
		info->description = ZH_WORDS_GETTER("workhistory.field.workunit");
	}

	//部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("workhistory.field.BM");
	}

	//职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("workhistory.field.zw");
	}

	//岗位
	DTO_FIELD(String,gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("workhistory.field.gw");
	}

	//职级
	DTO_FIELD(String,ormrankid);
	DTO_FIELD_INFO(ormrankid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormrankid");
	}

	//人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYPAGEQUERY_H_