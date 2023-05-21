#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _PIMPAPER_QUERY_
#define _PIMPAPER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 示例分页查询对象
 */
class PimpaperQuery : public PageQuery
{
	DTO_INIT(PimpaperQuery, PageQuery);

	//员工编号
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("sample.field.ygbh");
	}

	//员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("sample.field.pimpersonname");
	}

	////论文名称
	//DTO_FIELD(String, pimpapername);
	//DTO_FIELD_INFO(pimpapername) {
	//	info->description = ZH_WORDS_GETTER("sample.field.pimpapername");
	//}

	////出版社
	//DTO_FIELD(String, cbs);
	//DTO_FIELD_INFO(cbs) {
	//	info->description = ZH_WORDS_GETTER("sample.field.cbs");
	//}

	////刊物名称
	//DTO_FIELD(String, kwmc);
	//DTO_FIELD_INFO(kwmc) {
	//	info->description = ZH_WORDS_GETTER("sample.field.kwmc");
	//}

	////刊物期数
	//DTO_FIELD(String, gwqs);
	//DTO_FIELD_INFO(gwqs) {
	//	info->description = ZH_WORDS_GETTER("sample.field.gwqs");
	//}

	////发表时间
	//DTO_FIELD(String, fbsj);
	//DTO_FIELD_INFO(fbsj) {
	//	info->description = ZH_WORDS_GETTER("sample.field.fbsj");
	//}

	////个人在论文著作中的排名
	//DTO_FIELD(UInt64, grzlwzzzdpm);
	//DTO_FIELD_INFO(grzlwzzzdpm) {
	//	info->description = ZH_WORDS_GETTER("sample.field.grzlwzzzdpm");
	//}

	////附件
	//DTO_FIELD(String, fj);
	//DTO_FIELD_INFO(fj) {
	//	info->description = ZH_WORDS_GETTER("sample.field.fj");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PIMPAPER_QUERY_