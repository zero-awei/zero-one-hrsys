#pragma once
#ifndef _JOBTITLE_INFORMATION_PAGEQUERY_H_
#define _JOBTITLE_INFORMATION_PAGEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例职称分页查询对象
 */
class JobTitleInformationPageQuery : public PageQuery
{
	DTO_INIT(JobTitleInformationPageQuery, PageQuery);
	// 职称名称
	DTO_FIELD(String, professoranalysis_name);
	DTO_FIELD_INFO(professoranalysis_name) {
		info->description = ZH_WORDS_GETTER("sample.field.professoranalysis_name");
	}
	// 证书编号 credentials_num
	DTO_FIELD(String, credentials_num);
	DTO_FIELD_INFO(credentials_num) {
		info->description = ZH_WORDS_GETTER("sample.field.credentials_num");
	}
	// 职称等级 professor_grades
	DTO_FIELD(String, professor_grades);
	DTO_FIELD_INFO(professor_grades) {
		info->description = ZH_WORDS_GETTER("sample.field.professor_grades");
	}
	// 职称获取日期 zchqrq
	DTO_FIELD(String, zchqrq);
	DTO_FIELD_INFO(zchqrq) {
		info->description = ZH_WORDS_GETTER("sample.field.zchqrq");
	}
	// 评审单位 reviewbody
	DTO_FIELD(String, reviewbody);
	DTO_FIELD_INFO(reviewbody) {
		info->description = ZH_WORDS_GETTER("sample.field.reviewbody");
	}
	// 签发机构 lssuingagency
	DTO_FIELD(String, lssuingagency);
	DTO_FIELD_INFO(lssuingagency) {
		info->description = ZH_WORDS_GETTER("sample.field.lssuingagency");
	}
	//职称聘用时间 employtime
	DTO_FIELD(String, employtime);
	DTO_FIELD_INFO(employtime) {
		info->description = ZH_WORDS_GETTER("sample.field.employtime");
	}
	//是否最高职称 enable
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("sample.field.enable");
	}
	//员工编号:employeeid
	DTO_FIELD(String, employeeid);
	DTO_FIELD_INFO(employeeid) {
		info->description = ZH_WORDS_GETTER("sample.field.employeeid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOBTITLE_INFORMATION_PAGEQUERY_H_
