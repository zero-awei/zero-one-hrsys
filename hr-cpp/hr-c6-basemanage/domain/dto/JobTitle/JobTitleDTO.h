#pragma once
/**
* DTO是修改时携带参数和返回时携带参数类型
*/

#include "stdafx.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../../GlobalInclude.h"
#ifndef _JOBTITLE_DTO_
#define _JOBTITLE_DTO_

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 职称管理对象传输(临时字段)
*/
class JobTitleDTO : public oatpp::DTO {

	// 初始化DTO
	DTO_INIT(JobTitleDTO, DTO);

	// 主键唯一标识
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("title.field.id");
	}

	// 员工编号
	DTO_FIELD(UInt64, employee_id);
	DTO_FIELD_INFO(employee_id) {
		info->description = ZH_WORDS_GETTER("title.field.employee_id");
	}

	// 员工姓名
	DTO_FIELD(String, employee_name);
	DTO_FIELD_INFO(employee_name) {
		info->description = ZH_WORDS_GETTER("title.field.employee_name");
	}

	// 员工状态
	DTO_FIELD(String, employee_state);
	DTO_FIELD_INFO(employee_state) {
		info->description = ZH_WORDS_GETTER("title.field.employee_state");
	}
	// 组织名称
	DTO_FIELD(String, org_name);
	DTO_FIELD_INFO(org_name) {
		info->description = ZH_WORDS_GETTER("title.field.org_name");
	}
	// 职称名称
	DTO_FIELD(String, jobtitle_name);
	DTO_FIELD_INFO(jobtitle_name) {
		info->description = ZH_WORDS_GETTER("title.field.jobtitle_name");
	}
	// 获取日期
	DTO_FIELD(String, get_time);
	DTO_FIELD_INFO(get_time) {
		info->description = ZH_WORDS_GETTER("title.field.get_time");
	}
	// 证书编号
	DTO_FIELD(UInt64, certificate_id);
	DTO_FIELD_INFO(certificate_id) {
		info->description = ZH_WORDS_GETTER("title.field.certificate_id");
	}

	// 专业类别
	DTO_FIELD(String, professional_cate);
	DTO_FIELD_INFO(professional_cate) {
		info->description = ZH_WORDS_GETTER("title.field.professional_cate");
	}

	// 专业名称
	DTO_FIELD(String, professional_name);
	DTO_FIELD_INFO(professional_name) {
		info->description = ZH_WORDS_GETTER("title.field.professional_name");
	}

	// 职称等级
	DTO_FIELD(String, jobtitle_grades);
	DTO_FIELD_INFO(jobtitle_grades) {
		info->description = ZH_WORDS_GETTER("title.field.jobtitle_grades");
	}

	// 签发机构
	DTO_FIELD(String, issuing_authority);
	DTO_FIELD_INFO(issuing_authority) {
		info->description = ZH_WORDS_GETTER("title.field.issuing_authority");
	}
	// 评审单位
	DTO_FIELD(String, judging_unit);
	DTO_FIELD_INFO(judging_unit) {
		info->description = ZH_WORDS_GETTER("title.field.judging_unit");
	}
	// 职称聘用时间
	DTO_FIELD(String, title_employment_time);
	DTO_FIELD_INFO(title_employment_time) {
		info->description = ZH_WORDS_GETTER("title.field.judging_unit");
	}

	// 是否最高职称
	DTO_FIELD(String, b_highest_professional_title);
	DTO_FIELD_INFO(b_highest_professional_title) {
		info->description = ZH_WORDS_GETTER("title.field.b_highest_professional_title");
	}
};

/**
 * 职称管理分页对象传输
 */
class JobTitlePageDTO : public PageDTO<JobTitleDTO::Wrapper>
{
	DTO_INIT(JobTitlePageDTO, PageDTO<JobTitleDTO::Wrapper>);
};

/*用于删除DTO*/
class JobTitleDeleteDTO :public oatpp::DTO {
	DTO_INIT(JobTitleDeleteDTO, DTO);
	DTO_FIELD(List<UInt64>, list_jobtitle_id);
	DTO_FIELD_INFO(list_jobtitle_id) {
		info->description = ZH_WORDS_GETTER("title.delete.list_jobtitle_id");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_JOBTITLE_DTO_