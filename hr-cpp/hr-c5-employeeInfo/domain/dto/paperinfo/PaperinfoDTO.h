#pragma once


#ifndef _PAPERINFO_DTO_
#define _PAPERINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 专利信息传输对象
 */
class PaperinfoDTO : public oatpp::DTO
{

public:
    PaperinfoDTO() {};

    DTO_INIT(PaperinfoDTO, DTO);


	//GRZLWZZZDPM:个人在论文著作中的排名
	DTO_FIELD(String, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.grzlwzzzdpm");
	}
	//UPDATEMAN:更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updateman");
	}
	//PIMPAPERID:论文信息标识
	DTO_FIELD(String, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
	}
	//CREATEDATE:建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createdate");
	}
	//UPDATEDATE:更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updatedate");
	}
	//CREATEMAN:建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createman");
	}
	//FBSJ:发表时间
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fbsj");
	}
	//PIMPAPERNAME:论文名称
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpapername");
	}
	//CBSHKWMC:出版社或刊物名称
	DTO_FIELD(String, cbshkwmc);
	DTO_FIELD_INFO(cbshkwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbshkwmc");
	}
	//PIMPERSONID:人员信息标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpersonid");
	}
	//FJ:附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fj");
	}
	//JLSPZT:审批状态
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlspzt");
	}
	//JLGLBH:记录管理编号
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlglbh");
	}
	//JLCZZ:记录操作者
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlczz");
	}
	//JLSS:记录所属
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlss");
	}
	//CBS:出版社
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbs");
	}
	//KWMC:刊物名称
	DTO_FIELD(String, kwmc);
	DTO_FIELD_INFO(kwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwmc");
	}
	//KWQS:刊物期数
	DTO_FIELD(String, kwqs);
	DTO_FIELD_INFO(kwqs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwqs");
	}
	//REASON:拒绝原因
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.reason");
	}


};

/**
 * 分页传输对象
 */
class PaperinfoPageDTO : public PageDTO<PaperinfoDTO::Wrapper>
{
    DTO_INIT(PaperinfoPageDTO, PageDTO<PaperinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
