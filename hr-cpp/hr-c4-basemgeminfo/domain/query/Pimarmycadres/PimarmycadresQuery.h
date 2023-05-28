#pragma once
#ifndef _PIMARMYCADRES_QUERY_H_
#define _PIMARMYCADRES_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个查询用户信息的数据传输模型
 */
class PimarmycadresQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(PimarmycadresQuery, DTO);

	DTO_FIELD(String, pimid);
	DTO_FIELD_INFO(pimid) {
		info->description = ZH_WORDS_GETTER("Pimarmycadres.field.pimid");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif 
