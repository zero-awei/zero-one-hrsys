#pragma once
/**
 * 人员花名册 - 离职人员Query实现 - 楚孟献
 */

#ifndef _FORMER_EMPLOYEES_QUERY_
#define _FORMER_EMPLOYEES_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormerEmployeesQuery : public PageQuery
{
	DTO_INIT(FormerEmployeesQuery, PageQuery); 
	// 编号或名称
	DTO_FIELD(String, id_or_name);
	DTO_FIELD_INFO(id_or_name) {
		info->description = ZH_WORDS_GETTER("sample.field.id_or_name");
	}
	//// 编号
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("sample.field.id");
	//}
	//// 编号
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("sample.field.id");
	//}
	//// 姓名
	//DTO_FIELD(String, name);
	//DTO_FIELD_INFO(name) {
	//	info->description = ZH_WORDS_GETTER("sample.field.name");
	//}
	//// 年龄
	//DTO_FIELD(Int32, age);
	//DTO_FIELD_INFO(age) {
	//	info->description = ZH_WORDS_GETTER("sample.field.age");
	//}
	//// 性别
	//DTO_FIELD(String, sex);
	//DTO_FIELD_INFO(sex) {
	//	info->description = ZH_WORDS_GETTER("sample.field.sex");
	//}
	//// 组织
	//DTO_FIELD(String, organization);
	//DTO_FIELD_INFO(organization) {
	//	info->description = ZH_WORDS_GETTER("sample.field.organization");
	//}
	//// 部门
	//DTO_FIELD(String, department);
	//DTO_FIELD_INFO(department) {
	//	info->description = ZH_WORDS_GETTER("sample.field.department");
	//}
	//// 职级
	//DTO_FIELD(String, rank);
	//DTO_FIELD_INFO(rank) {
	//	info->description = ZH_WORDS_GETTER("sample.field.rank");
	//}
	//// 通讯地址
	//DTO_FIELD(String, mail_address);
	//DTO_FIELD_INFO(mail_address) {
	//	info->description = ZH_WORDS_GETTER("sample.field.mail_address");
	//}
	//// 家庭联系人
	//DTO_FIELD(String, family_contact);
	//DTO_FIELD_INFO(family_contact) {
	//	info->description = ZH_WORDS_GETTER("sample.field.family_contact");
	//}
	//// 家庭联系人电话
	//DTO_FIELD(String, family_contact_number);
	//DTO_FIELD_INFO(family_contact_number) {
	//	info->description = ZH_WORDS_GETTER("sample.field.family_contact_number");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif 