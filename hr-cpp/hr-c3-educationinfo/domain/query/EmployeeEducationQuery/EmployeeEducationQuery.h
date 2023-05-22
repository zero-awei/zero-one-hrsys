#pragma once
#ifndef _Employee_Education_Query
#define _Employee_Education_Query

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询指定员工教育信息
 */
class EmployeeEducationQuery :public oatpp::DTO
{
	DTO_INIT(EmployeeEducationQuery, DTO);

	//教育信息
	//学历
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("employee.education.degree");
	}
	//入学时间
	DTO_FIELD(String, enrollmentDate);
	DTO_FIELD_INFO(enrollmentDate) {
		info->description = ZH_WORDS_GETTER("employee.field.education");
	}
	//毕业时间
	DTO_FIELD(String, graduationDate);
	DTO_FIELD_INFO(graduationDate) {
		info->description = ZH_WORDS_GETTER("employee.education.graduationDate");
	}
	//毕业院校
	DTO_FIELD(String, graduatedInstitution);
	DTO_FIELD_INFO(graduatedInstitution) {
		info->description = ZH_WORDS_GETTER("employee.education.graduatedInstitution");
	}
	//一级学科
	DTO_FIELD(String, primaryDiscipline);
	DTO_FIELD_INFO(primaryDiscipline) {
		info->description = ZH_WORDS_GETTER("employee.education.primaryDiscipline");
	}
	//所学专业
	DTO_FIELD(String, major);
	DTO_FIELD_INFO(major) {
		info->description = ZH_WORDS_GETTER("employee.education.major");
	}
	//学习形式
	DTO_FIELD(String, studyFormat);
	DTO_FIELD_INFO(studyFormat) {
		info->description = ZH_WORDS_GETTER("employee.education.studyFormat");
	}
	//学校性质
	DTO_FIELD(String, schoolNature);
	DTO_FIELD_INFO(schoolNature) {
		info->description = ZH_WORDS_GETTER("employee.education.schoolNature");
	}
	//是否第一学历
	DTO_FIELD(Boolean, firstDegree);
	DTO_FIELD_INFO(firstDegree) {
		info->description = ZH_WORDS_GETTER("employee.education.firstDegree");
	}
	//最高学历
	DTO_FIELD(String, highestEducationDegree);
	DTO_FIELD_INFO(highestEducationDegree) {
		info->description = ZH_WORDS_GETTER("employee.education.highestEducationDegree");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
