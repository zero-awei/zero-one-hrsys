#pragma once
#ifndef _WORKHISTORY_QUERY_H_
#define _WORKHISTORY_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个查询用户信息的数据传输模型
 */
class WorkHistoryQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(WorkHistoryQuery, PageQuery);
	//rzkssj: 任职开始时间
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("use.field.rzkssj");
	}
	//rzjssj: 任职结束时间
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("use.field.rzjssj");
	}
	//ormorgname: 工作单位
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("use.field.ormorgname");
	}
	//ormdutyname: 职务
	DTO_FIELD(String, ormdutyname);
	DTO_FIELD_INFO(ormdutyname) {
		info->description = ZH_WORDS_GETTER("use.field.ormdutyname");
	}
	//ormpostname: 岗位
	DTO_FIELD(String, ormpostname);
	DTO_FIELD_INFO(ormpostname) {
		info->description = ZH_WORDS_GETTER("use.field.ormpostname");
	}
	//cfplx: 兼职借调类型
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("use.field.cfplx");
	}
	//enable: 是否主要经历
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("use.field.enable");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
