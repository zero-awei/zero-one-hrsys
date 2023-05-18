#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/17 8:53:26

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
#ifndef _WORKHISTORYEXPORTQUERY_H_
#define _WORKHISTORYEXPORTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)



class WorkHistoryExportQuery : public PageQuery
{
	DTO_INIT(WorkHistoryExportQuery, PageQuery);


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
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
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
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("workhistory.field.gw");
	}

	//7兼职借调类型
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("workhistory.field.cfplx");
	}

	//8是否主要经历
	DTO_FIELD(UInt64, experience);
	DTO_FIELD_INFO(experience) {
		info->description = ZH_WORDS_GETTER("workhistory.field.experience");
	}

	//工作履历信息id
	DTO_FIELD(String, pimworkhistoryid);
	DTO_FIELD_INFO(pimworkhistoryid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimworkhistoryid");
	}
	//人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYEXPORTQUERY_H_