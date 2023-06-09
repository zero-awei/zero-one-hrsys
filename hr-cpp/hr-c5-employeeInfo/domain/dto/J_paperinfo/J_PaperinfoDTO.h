#pragma once


#ifndef _J_PAPERINFO_DTO_
#define _J_PAPERINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息传输对象
 */
class J_PaperinfoDTO : public oatpp::DTO
{

public:
	J_PaperinfoDTO() {};

    DTO_INIT(J_PaperinfoDTO, DTO);

	//CBS:出版社
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbs");
	}
	//CBSHKWMC:出版社或刊物名称
	DTO_FIELD(String, cbshkwmc);
	DTO_FIELD_INFO(cbshkwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbshkwmc");
	}
	//CREATEDATE:建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createdate");
	}
	//CREATEMAN:建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createman");
	}
	//ENABLE
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.enable");
	}
	//FBSJ:发表时间
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fbsj");
	}
	//FJ:附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fj");
	}
	//GRZLWZZZDPM:个人在论文著作中的排名
	DTO_FIELD(String, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.grzlwzzzdpm");
	}
	//JLCZZ:记录操作者
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlczz");
	}
	//JLGLBH:记录管理编号
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlglbh");
	}
	//JLSPZT:审批状态
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlspzt");
	}
	//JLSS:记录所属
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlss");
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
	//ORGID:组织标识1
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.orgid");
	}
	//ORGSECTORID:部门标识1
	DTO_FIELD(String, orgsectorid);
	DTO_FIELD_INFO(orgsectorid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.orgsectorid");
	}
	//ORMORGID:组织标识2
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.ormorgid");
	}
	//ORMORGSECTORID:部门标识2
	DTO_FIELD(String, ormorgsectorid);
	DTO_FIELD_INFO(ormorgsectorid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.ormorgsectorid");
	}
	//PIMPAPERID:论文信息标识
	DTO_FIELD(String, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
	}
	//PIMPAPERNAME:论文名称
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpapername");
	}
	//PIMPERSONID:人员信息标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpersonid");
	}
	//PIMPERSONNAME:员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpersonname");
	}
	//REASON:拒绝原因
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.reason");
	}
	//UPDATEDATE:更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updatedate");
	}
	//UPDATEMAN:更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updateman");
	}
	//YGBH:员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.ygbh");
	}

};

/**
 * 修改论文信息传输对象
 */
class ModifyPaperinfoDTO : public oatpp::DTO
{

public:
	ModifyPaperinfoDTO() {};

	DTO_INIT(ModifyPaperinfoDTO, DTO);

	//PIMPAPERID:论文信息标识
	DTO_FIELD(String, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
	}

	//PIMPAPERNAME:论文名称
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpapername");
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
	//FBSJ:发表时间
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fbsj");
	}
	//GRZLWZZZDPM:个人在论文著作中的排名
	DTO_FIELD(String, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.grzlwzzzdpm");
	}
	//FJ:附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fj");
	}

	//UPDATEDATE:更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updatedate");
	}
	//UPDATEMAN:更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updateman");
	}

};
/**
 * 分页传输对象
 */
class J_PaperinfoPageDTO : public PageDTO<J_PaperinfoDTO::Wrapper>
{
    DTO_INIT(J_PaperinfoPageDTO, PageDTO<J_PaperinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
