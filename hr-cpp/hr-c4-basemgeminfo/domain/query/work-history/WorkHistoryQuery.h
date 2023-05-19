#pragma once
#ifndef _WORKHISTORY_QUERY_H_
#define _WORKHISTORY_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个查询用户信息的数据传输模型
 */
class WorkHistoryQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(WorkHistoryQuery, DTO);
	
	//ormorgname: 工作单位
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif 
