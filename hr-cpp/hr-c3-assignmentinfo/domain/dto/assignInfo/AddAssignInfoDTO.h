#ifndef _Add_Assign_Info_DTO_
#define _Add_Assign_Info_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增指定员工分配信息
 */
class AddAssignInfoDTO : public oatpp::DTO
{
	DTO_INIT(AddAssignInfoDTO, DTO);
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
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("employee.field.type");
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
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("employee.field.start-time");
	}
	// 任职结束时间
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("employee.field.end-time");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_Add_Assign_Info_DTO_