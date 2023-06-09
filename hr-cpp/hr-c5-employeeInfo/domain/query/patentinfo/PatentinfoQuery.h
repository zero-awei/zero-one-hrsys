#pragma once
#ifndef _PAPER_QUERY_
#define _PAPER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * 专利信息查询对象
 */
class PatentinfoQuery : public PageQuery
{
	DTO_INIT(PatentinfoQuery, PageQuery);


	//// 人员信息标识
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("patentInformation.field.PIMPERSONID");
	//}

	// 专利信息编码
	DTO_FIELD(String, PIMPATENTID);
	DTO_FIELD_INFO(PIMPATENTID) {
		info->description = ZH_WORDS_GETTER("patentInformation.field.PIMPATENTID");
	}



};



#include OATPP_CODEGEN_END(DTO)
#endif
