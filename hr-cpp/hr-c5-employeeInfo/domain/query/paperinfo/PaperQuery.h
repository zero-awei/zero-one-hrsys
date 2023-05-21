#pragma once
#ifndef _PAPER_QUERY_
#define _PAPER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息分页查询对象
 */
class PaperQuery : public PageQuery
{
	DTO_INIT(PaperQuery, PageQuery);
	// 员工编号
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
	}
	//// 出版社
	//DTO_FIELD(String, cbs);
	//DTO_FIELD_INFO(cbs) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.cbs");
	//}
	//// 发表时间
	//DTO_FIELD(String, fbsj);
	//DTO_FIELD_INFO(fbsj) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.fbsj");
	//}
	//// 刊物期数
	//DTO_FIELD(String, kwqs);
	//DTO_FIELD_INFO(kwqs) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.kwqs");
	//}
	//// 附件
	//DTO_FIELD(String, fj);
	//DTO_FIELD_INFO(fj) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.fj");
	//}
	//// 个人在论文著作中的排名
	//DTO_FIELD(Int32, grzlwzzzdpm);
	//DTO_FIELD_INFO(grzlwzzzdpm) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.grzlwzzzdpm");
	//}
	//// 刊物名称
	//DTO_FIELD(String, kwmc);
	//DTO_FIELD_INFO(kwmc) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.kwmc");
	//}
	//// 论文名称
	//DTO_FIELD(String, pimpapername);
	//DTO_FIELD_INFO(pimpapername) {
	//	info->description = ZH_WORDS_GETTER("paperinfo.field.pimpapername");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif