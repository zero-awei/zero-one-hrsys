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
	
	//任职开始时间
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzkssj");
	}


	//任职结束时间
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzjssj");
	}

	//工作单位
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	}

	//4部门
	DTO_INIT_(String, ormorgsectorname, "workhistory.field.ormorgsectorname")

	//5职务
	DTO_INIT_(String, ormdutyname, "workhistory.field.ormdutyname")

	//6岗位
	DTO_INIT_(String, ormpostname, "workhistory.field.ormpostname")

	//7兼职借调类型
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("workhistory.field.cfplx");
	}

	//8是否主要经历
	DTO_FIELD(UInt64, experience);
	DTO_FIELD_INFO(experience) {
		info->description = ZH_WORDS_GETTER("workhistory.field.experience");
	}
	//人员信息id
	DTO_FIELD(String, pimpersionid);
	DTO_FIELD_INFO(pimpersionid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}

	//人员信息标识pimworkhistoryid
	DTO_FIELD(String, pimworkhistoryid);
	DTO_FIELD_INFO(pimworkhistoryid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimworkhistoryid");
	}
	//更新时间updatedate
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("workhistory.field.updatedate");
	}
	//更新人updateman
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("workhistory.field.updateman");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif 
