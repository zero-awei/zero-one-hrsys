#pragma once
/**
* 分页查询证书列表--(证书管理-分页查询证书列表)--pine
 */
#ifndef _CHECK_CER_QUERY_
#define _CHECK_CER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

 /**
 证书管理-分页查询证书列表--pine
  */
class CheckCerListQuery : public PageQuery
{
	DTO_INIT(CheckCerListQuery, PageQuery);
	// 员工编号
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// 员工姓名
	DTO_FIELD(String, pimperSonName);
	DTO_FIELD_INFO(pimperSonName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimperSonName");
	}
	// 证书名称
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CheckCerList_QUERY_