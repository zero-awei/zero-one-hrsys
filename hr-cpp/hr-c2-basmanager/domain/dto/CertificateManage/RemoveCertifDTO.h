#pragma once
/*
（证书管理-证书信息-删除证书（支持批量删除））--洛洛
*/
#ifndef _REMOVECERTIF_DTO_
#define _REMOVECERTIF_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class RemoveCertifDTO : public oatpp::DTO
{
	DTO_INIT(RemoveCertifDTO, DTO);
	DTO_FIELD(List<String>, idByBatch) = {};
	DTO_FIELD_INFO(idByBatch) {
		info->description= ZH_WORDS_GETTER("certif.field.idByBatch");
	}
	/*
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("certif.field.id");
	}
	*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REMOVECERTIF_DTO_