
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
/**
 * 语言能力DO模型
 */
class LanguageDO
{
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
	//人员信息标识
	CC_SYNTHESIZE(string, personID, PersonID);

public:
	LanguageDO() {
		gainTime = "";
		attachment = "";
		languageType = "";
		createMan = "";
		updateMan = "";
		languageLevel = "";
		personID = "";
	}
};

#endif // !_LANGUAGEDO_H_#pragma once
