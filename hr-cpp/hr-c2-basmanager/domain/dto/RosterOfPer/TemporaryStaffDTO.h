#pragma once
#ifndef _TEMPORARYSTAFFDTO_H_
#define _TEMPORARYSTAFFDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 挂职人员传输对象--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */
class TemporaryStaffDTO : public oatpp::DTO {
public:
	DTO_INIT(TemporaryStaffDTO, DTO);
	//员工编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.id");
	}
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.name");
	}
	//员工状态
	DTO_FIELD(String, empStatus);
	DTO_FIELD_INFO(empStatus) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.empStatus");
	}
	//挂职状态
	DTO_FIELD(String, tempStatus);
	DTO_FIELD_INFO(tempStatus) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempStatus");
	}
	//挂职组织
	DTO_FIELD(String, tempOrg);
	DTO_FIELD_INFO(tempOrg) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempOrg");
	}
	//挂职部门
	DTO_FIELD(String, tempDept);
	DTO_FIELD_INFO(tempDept) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempDept");
	}
	//挂职开始时间
	DTO_FIELD(String, tempStartTime);
	DTO_FIELD_INFO(tempStartTime) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempStartTime");
	}
	//挂职结束时间
	DTO_FIELD(String, tempEndTime);
	DTO_FIELD_INFO(tempEndTime) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempEndTime");
	}
	//挂职人员唯一标识
	DTO_FIELD(String, pimpersonId);
	DTO_FIELD_INFO(pimpersonId) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.pimpersonId");
	}
};

/**
 * 挂职人员分页传输对象
 */
class TemporaryStaffPageDTO : public PageDTO<TemporaryStaffDTO::Wrapper>
{
	DTO_INIT(TemporaryStaffPageDTO, PageDTO<TemporaryStaffDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPORARYSTAFFDTO_H_