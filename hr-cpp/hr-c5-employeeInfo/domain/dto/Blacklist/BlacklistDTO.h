#pragma once

#ifndef _BLACKLIST_DTO_
#define _BLACKLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class BlacklistDTO : public oatpp::DTO {
	DTO_INIT(BlacklistDTO, DTO);
	//员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("blacklist.field.ygbh");
	}
    //员工姓名
	DTO_FIELD(String, ygxm);
	DTO_FIELD_INFO(ygxm) {
		info->description = ZH_WORDS_GETTER("blacklist.field.ygxm");
	}
	//证件号码
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("blacklist.field.zjhm");
	}
	//组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("blacklist.field.zz");
	}
	//员工状态
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("blacklist.field.ygzt");
	}
	//是否列入黑名单
	DTO_FIELD(String, sflrhmd);
	DTO_FIELD_INFO(sflrhmd) {
		info->description = ZH_WORDS_GETTER("blacklist.field.sflrhmd");
	}
	//黑名单原因
	DTO_FIELD(String, hmdyy);
	DTO_FIELD_INFO(hmdyy) {
		info->description = ZH_WORDS_GETTER("blacklist.field.hmdyy");
	}
};

class BlacklistPageDTO : public PageDTO<BlacklistDTO::Wrapper>
{
	DTO_INIT(BlacklistPageDTO, PageDTO<BlacklistDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_BLACKLIST_DTO_
