#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/23 10:42:48

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
#ifndef _WORKHISTORYINTOQUERY_H_
#define _WORKHISTORYINTOQUERY_H_

#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistoryIntoQuery : public PageQuery
{
	DTO_INIT(WorkHistoryIntoQuery, PageQuery);
	
	//9人员信息id
	DTO_INIT_(String, pimpersonid, "workhistory.field.pimpersonid")


	//导入文件后缀名
	DTO_INIT_(String, suffix, "workhistory.field.suffix")


	//导出文件主体
	DTO_INIT_(String, body, "workhistory.field.body")
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYINTOQUERY_H_