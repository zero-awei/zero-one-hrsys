#pragma once
#ifndef _Assign_Info_Query
#define _Assign_Info_Query


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 查找指定员工分配信息
 */
class AssignInfoQuery : public PageQuery
{
	DTO_INIT(AssignInfoQuery, PageQuery);
	//编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	// 分配(主分配或次分配)
	DTO_FIELD(String, assign);
	DTO_FIELD_INFO(assign) {
		info->description = ZH_WORDS_GETTER("employee.field.assign");
	}
	// 类型
	DTO_FIELD(String, Etype);
	DTO_FIELD_INFO(Etype) {
		info->description = ZH_WORDS_GETTER("employee.field.Etype");
	}
	// 组织
	DTO_FIELD(String, organize);
	DTO_FIELD_INFO(organize) {
		info->description = ZH_WORDS_GETTER("employee.field.organize");
	}
	// 部门
	DTO_FIELD(String, depart);
	DTO_FIELD_INFO(depart) {
		info->description = ZH_WORDS_GETTER("employee.field.depart");
	}
	// 职务
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("employee.field.job");
	}
	// 岗位
	DTO_FIELD(String, post);
	DTO_FIELD_INFO(post) {
		info->description = ZH_WORDS_GETTER("employee.field.post");
	}
	// 任职开始时间
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("employee.field.startTime");
	}
	// 任职结束时间
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("employee.field.endTime");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Assign_Info_Query