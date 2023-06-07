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
#ifndef _LANGUAGE_SERVICE_
#define _LANGUAGE_SERVICE_
#include <list>
#include "domain/query/language/LanguageQuery.h"
#include "domain/dto/language/LanguageDTO.h"
#include "domain/query/languagePage/LanguagePageQuery.h"
#include "domain/dto/importLanguage/ImportLanguageDTO.h"
#include "domain/dto/deleteLanguage/DeleteLanguageDTO.h"

/**
 * 语言能力相关服务实现
 * 负责人：君
 */
class LanguageService 
{
public:
	// 分页查询所有数据
	LanguagePageDTO::Wrapper listAll(const LanguagePageQuery::Wrapper& query);
	//通过Id查询数据
	LanguageDTO::Wrapper queryOneDataById(const LanguageQuery::Wrapper& query);
	// 保存数据
	int saveData(const LanguageDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const LanguageDTO::Wrapper& dto);
	//删除数据
	int removeData(const DeleteLanguageDTO::Wrapper& dto);
};
#endif // !_LANGUAGE_SERVICE_