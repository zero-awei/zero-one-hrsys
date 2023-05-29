#ifndef JOBTITLEYDTO_H
#define JOBTITLEYDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 职称DTO
 */
class JobTitleInfoDTO : public oatpp::DTO
{
	DTO_INIT(JobTitleInfoDTO, DTO);
	
	// 员工编号
	DTO_FIELD(UInt32, employee_id);
	DTO_FIELD_INFO(employee_id) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.employee_id");
	}

	// 证书编号
	DTO_FIELD(UInt32, certificate_id);
	DTO_FIELD_INFO(certificate_id) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.certificate_id");
	}

	// 员工姓名
	DTO_FIELD(String, employee_name);
	DTO_FIELD_INFO(employee_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.employee_name");
	}
	// 组织名称
	DTO_FIELD(String, org_name);
	DTO_FIELD_INFO(org_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.org_name");
	}
	// 职称名称
	DTO_FIELD(String, jobtitle_name);
	DTO_FIELD_INFO(jobtitle_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
	}
	// 职称等级
	DTO_FIELD(String, professor_grades);
	DTO_FIELD_INFO(professor_grades) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.professor_grades");
	}
	// 获取日期
	DTO_FIELD(String, get_time);
	DTO_FIELD_INFO(get_time) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.get_time");
	}
	// 专业类别
	DTO_FIELD(String, professional_cate);
	DTO_FIELD_INFO(professional_cate) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.professional_cate");
	}
	// 专业名称
	DTO_FIELD(String, professional_name);
	DTO_FIELD_INFO(professional_name) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.professional_name");
	}
	// 签发机构
	DTO_FIELD(String, issuing_authority);
	DTO_FIELD_INFO(issuing_authority) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.issuing_authority");
	}
	// 评审单位
	DTO_FIELD(String, judging_unit);
	DTO_FIELD_INFO(judging_unit) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.judging_unit");
	}
	// 是否最高职称
	DTO_FIELD(Boolean, b_highest_professional_title);
	DTO_FIELD_INFO(b_highest_professional_title) {
		info->description = ZH_WORDS_GETTER("jobtitle.field.b_highest_professional_title");
	}
};
#endif