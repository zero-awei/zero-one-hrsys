/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/20 20:28:15
*/
#ifndef _EDUCATIONIMPORTVO_H_
#define _EDUCATIONIMPORTVO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EudacationImportVO : public oatpp::DTO
{
	DTO_INIT(EudacationImportVO, DTO);
	DTO_FIELD(List<String>, newId) = {};
	DTO_FIELD_INFO(newId) {
		info->description = ZH_WORDS_GETTER("EudacationImport.id");
	}
};
/**
 * 使用JsonVO封装ImportJobVO
 * 负责人：Andrew 大佬牛逼
 */
class EudacationImportJsonVO : public JsonVO<EudacationImportVO::Wrapper>
{
	DTO_INIT(EudacationImportJsonVO, JsonVO<EudacationImportVO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONIMPORTVO_H_#pragma once
