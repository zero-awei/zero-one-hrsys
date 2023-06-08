#pragma once
#ifndef _SCIENTIFICDTO_H_
#define _SCIENTIFICDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class ScientificDTO : public oatpp::DTO {
	DTO_INIT(ScientificDTO, DTO);

	//更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("scientific.updateman");
	}

	//科研成果名称
	DTO_FIELD(String, pimresearchfindingsname);
	DTO_FIELD_INFO(pimresearchfindingsname) {
		info->description = ZH_WORDS_GETTER("scientific.pimresearchfindingsname");
	}

	//附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("scientific.fj");
	}

	// ENABLE
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("scientific.enable");
	}

	//建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("scientific.createdate");
	}

	//更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("scientific.updatedate");
	}

	//建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("scientific.createman");
	}

	//科研成果标识
	DTO_FIELD(String, pimresearchfindingsid);
	DTO_FIELD_INFO(pimresearchfindingsid) {
		info->description = ZH_WORDS_GETTER("scientific.pimresearchfindingsid");
	}

	//人员信息标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("scientific.pimpersonid");
	}

	//获取时间
	DTO_FIELD(String, hqsj);
	DTO_FIELD_INFO(hqsj) {
		info->description = ZH_WORDS_GETTER("scientific.hqsj");
	}

	//记录所属
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("scientific.jlss");
	}
	//审批状态
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("scientific.jlspzt");
	}
	//记录管理编号
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("scientific.jlglbh");
	}
	//记录操作者
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("scientific.jlczz");
	}
	//拒绝原因
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("scientific.reason");
	}
};

class ScientificPageDTO : public PageDTO<ScientificDTO::Wrapper>
{
	DTO_INIT(ScientificPageDTO, PageDTO<ScientificDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SCIENTIFICDTO_H_