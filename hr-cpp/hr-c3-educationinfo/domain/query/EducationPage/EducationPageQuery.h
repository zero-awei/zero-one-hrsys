/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/17 21:30:53
*/
#ifndef _GETEDUCATIONPAGEQUERY_H_
#define _GETEDUCATIONPAGEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//功能1：根据员工姓名 分页查询 教育信息
class EducationPageQuery : public PageQuery
{
	DTO_INIT(EducationPageQuery, PageQuery);
	// 员工id pimpersonid
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	}
	// 员工姓名pimpersonname
	/*DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("t_pimperson.pimpersonname");
	}*/
	// 排序类别:排序方式,(asc/desc)
	//DTO_FIELD(String, sort);
	//DTO_FIELD_INFO(sort) {
	//	info->description = ZH_WORDS_GETTER("t_pimperson.sort");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETEDUCATIONPAGEQUERY_H_