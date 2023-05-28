#pragma once

#ifndef _EMPLOYEE_NOT_IN_AECHIVE_DTO_
#define _EMPLOYEE_NOT_IN_AECHIVE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class EmployeeNotInArchiveDto : public oatpp::DTO
{
	DTO_INIT(EmployeeNotInArchiveDto, DTO);
	// 档案编号
	DTO_FIELD(String, nummber);
	DTO_FIELD_INFO(nummber) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.nummber");
	}
	// 管理单位
	DTO_FIELD(String, gunits);
	DTO_FIELD_INFO(gunits) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field. gunits");
	}
	// 档案保管地
	DTO_FIELD(String, pos);
	DTO_FIELD_INFO(pos) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.pos");
	}
	// 档案室
	DTO_FIELD(String, office);
	DTO_FIELD_INFO(office) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.office");
	}
	// 档案状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.status");
	}
	// 员工编号
	DTO_FIELD(String, emloyeenumber);
	DTO_FIELD_INFO(emloyeenumber) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.emloyeenumber");
	}
	// 员工姓名
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
	}
	// 所属单位
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.unit");
	}
	// 员工状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.state");
	}
	// 操作列
	DTO_FIELD(String, use);
	DTO_FIELD_INFO(use) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.use");
	}
};


class ArchiveOutDto : public oatpp::DTO
{
	DTO_INIT(ArchiveOutDto, DTO);
	// 员工编号
	DTO_FIELD(String, emloyeenumber);
	DTO_FIELD_INFO(emloyeenumber) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.emloyeenumber");
	}
	// 员工姓名
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
	}
	// 调出单位
	DTO_FIELD(String, outunit);
	DTO_FIELD_INFO(outunit) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.outunit");
	}
	// 调入单位
	DTO_FIELD(String, inunit);
	DTO_FIELD_INFO(inunit) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.inunit");
	}
	// 调动时间
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.time");
	}
};
/**
 * 示例分页传输对象
 */
class EmployeeNotInArchivePageDTO : public PageDTO<EmployeeNotInArchiveDto::Wrapper>
{
	DTO_INIT(EmployeeNotInArchivePageDTO, PageDTO<EmployeeNotInArchiveDto::Wrapper>);
};

class ArchiveOutPageDTO : public PageDTO<ArchiveOutDto::Wrapper>
{
	DTO_INIT(ArchiveOutPageDTO, PageDTO<ArchiveOutDto::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_