#pragma once
#ifndef _PAPAER_DTO_
#define _PAPAER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息传输对象
 */
class PaperDTO : public oatpp::DTO
{
	DTO_INIT(PaperDTO, DTO);
	
	// 出版社
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.cbs");
	}
	// 发表时间
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.fbsj");
	}
	// 刊物期数
	DTO_FIELD(Int32, kwqs);
	DTO_FIELD_INFO(kwqs) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.kwqs");
	}
	// 附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.fj");
	}
	// 个人在论文著作中的排名
	DTO_FIELD(Int32, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.grzlwzzzdpm");
	}
	// 刊物名称
	DTO_FIELD(String, kwmc);
	DTO_FIELD_INFO(kwmc) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.kwmc");
	}
	// 论文名称
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.pimpapername");
	}
	// 编号
	DTO_FIELD(List<String>, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.PIMPAPERID");
	}
public:
	PaperDTO() {}
	/*PaperDTO(String cbs, String fbsj, String kwqs, String fj, Int32 grzlwzzzdpm, String kwmc) :
		cbs(cbs), fbsj(fbsj), kwqs(kwqs), fj(fj), grzlwzzzdpm(grzlwzzzdpm), kwmc(kwmc){}
	*/
};

/**
 * 论文信息分页传输对象
 */
class PaperPageDTO : public PageDTO<PaperDTO::Wrapper>
{
	DTO_INIT(PaperPageDTO, PageDTO<PaperDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif