#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/21 1:24:39

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
#ifndef _LANGUAGEPAGEQUERY_H_
#define _LANGUAGEPAGEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LanguagePageQuery : public PageQuery
{
	DTO_INIT(LanguagePageQuery, PageQuery);
	//语言标识能力ID
	API_DTO_FIELD_DEFAULT(String, languageAbilityID, u8"语言标识能力");
	//外语等级获取时间
	API_DTO_FIELD_DEFAULT(String, gainTime, u8"外语等级获取时间");
	//授权
	API_DTO_FIELD_DEFAULT(Int32, permission, u8"授权");
	//附件
	API_DTO_FIELD_DEFAULT(String, attachment, u8"附件");
	//语种
	API_DTO_FIELD_DEFAULT(String, languageType, u8"语种");
	//创建人
	API_DTO_FIELD_DEFAULT(String, createMan, u8"创建人");
	//更新人
	API_DTO_FIELD_DEFAULT(String, updateMan, u8"更新人");
	//语言等级
	API_DTO_FIELD_DEFAULT(String, languageLevel, u8"语言等级");
	//创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, u8"创建时间");
	//人员信息标识
	API_DTO_FIELD_DEFAULT(String, personID, u8"人员信息标识");
	//记录所属
	API_DTO_FIELD_DEFAULT(String, jlss, u8"记录所属");
	//记录管理编号
	API_DTO_FIELD_DEFAULT(String, jlglbh, u8"记录管理编号");
	//记录审批状态
	API_DTO_FIELD_DEFAULT(String, jlspzt, u8"记录审批状态");
	//记录操作者
	API_DTO_FIELD_DEFAULT(String, jlczz, u8"记录操作者");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGEPAGEQUERY_H_