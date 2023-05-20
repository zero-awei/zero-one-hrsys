#pragma once


#ifndef _FILESATATUSQUERY_H_
#define _FILESATATUSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class FilestatusQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(FilestatusQuery, PageQuery);
	//// 昵称
	//DTO_FIELD(String, nickname);
	//DTO_FIELD_INFO(nickname) {
	//	info->description = ZH_WORDS_GETTER("use.field.nickname");
	//}
	// 查询的时候是不是只需要将
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_