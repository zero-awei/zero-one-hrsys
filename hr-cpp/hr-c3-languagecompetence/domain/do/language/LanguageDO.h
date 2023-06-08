
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/23 20:34:46

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
#ifndef _LANGUAGEDO_H_
#define _LANGUAGEDO_H_
#include "../DoInclude.h"
#include <ctime> 
/**
 * 语言能力DO模型
 * 负责人：君
 */
class LanguageDO
{
	//语言标识能力ID
	CC_SYNTHESIZE(string, languageAbilityID, LanguageAbilityID);
	//更新时间
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	//许可的
	CC_SYNTHESIZE(int, permission, Permission);
	//外语等级获取时间
	CC_SYNTHESIZE(string, gainTime, GainTime);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//语种
	CC_SYNTHESIZE(string, languageType, LanguageType);
	//创建人
	CC_SYNTHESIZE(string, createMan, CreateMan);
	//更新人
	CC_SYNTHESIZE(string, updateMan, UpdateMan);
	//语言等级
	CC_SYNTHESIZE(string, languageLevel, LanguageLevel);
	//创建时间
	CC_SYNTHESIZE(string, createDate, CreateDate)
	//人员信息标识
	CC_SYNTHESIZE(string, personID, PersonID);
	//记录所属
	CC_SYNTHESIZE(string, jlss, JLSS);
	//记录管理编号
	CC_SYNTHESIZE(string, jlglbh, JLGLBH);
	//记录审批状态
	CC_SYNTHESIZE(string, jlspzt, JLSPZT);
	//记录操作者
	CC_SYNTHESIZE(string, jlczz, JLCZZ);

public:
	//初始化
	LanguageDO() {
		languageAbilityID = "";
		permission = 0;
		gainTime = "";
		attachment = "";
		languageType = "";
		createMan = "";
		updateMan = "";
		languageLevel = "";
		personID = "";
		jlss = "";
		jlglbh = "";
		jlspzt = "";
		jlczz = "";
	}
};

#endif // !_LANGUAGEDO_H_#pragma once
