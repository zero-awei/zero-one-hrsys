#ifndef _USERQUERY_H_
#define _USERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class GetAllotSingleQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(GetAllotSingleQuery, PageQuery);
	// 员工姓名pimpersonname
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("t_pimperson.pimpersonname");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_