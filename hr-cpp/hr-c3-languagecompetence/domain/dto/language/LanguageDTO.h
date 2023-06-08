#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/17 19:31:17

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
#ifndef _LANGUAGEDTO_H_
#define _LANGUAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 语言模块传输对象
 */
class LanguageDTO : public oatpp::DTO
{
	DTO_INIT(LanguageDTO, DTO);
	//语言能力标识Id
	API_DTO_FIELD_DEFAULT(String, languageAbilityID, u8"语言标识能力Id");
	//许可的
	API_DTO_FIELD_DEFAULT(Int32, permission, u8"授权");
	//外语等级获取时间
	API_DTO_FIELD_DEFAULT(String, gainTime, u8"外语等级获取时间");
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
/**
 * 语言模块分页传输对象
 */
class LanguagePageDTO : public PageDTO<LanguageDTO::Wrapper> 
{
	DTO_INIT(LanguagePageDTO, PageDTO<LanguageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGEDTO_H_