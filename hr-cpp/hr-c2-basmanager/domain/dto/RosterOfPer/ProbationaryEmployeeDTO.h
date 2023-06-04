#pragma once
#ifndef _PROBATIONARY_EMPLOYEE_DTO_
#define _PROBATIONARY_EMPLOYEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 人员花名册 - 试用人员DTO实现 - 楚孟献
 */
class ProbationaryEmployeeDTO : public oatpp::DTO
{
public:
	//无参构造
	ProbationaryEmployeeDTO() {};

	DTO_INIT(ProbationaryEmployeeDTO, DTO);
	// 唯一标识
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.PIMPERSONID");
	}
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名A
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zz");
	}
	// 部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
	}
	// 职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zw");
	}
	// 岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.gw");
	}
	// 任职时间
	DTO_FIELD(String, rzsj);
	DTO_FIELD_INFO(rzsj) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.rzsj");
	}
	// 试用到期时间
	DTO_FIELD(String, daoqishijian);
	DTO_FIELD_INFO(daoqishijian) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.time");
	}
};

class ProbationaryEmployeePageDTO : public PageDTO<ProbationaryEmployeeDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeePageDTO, PageDTO<ProbationaryEmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 