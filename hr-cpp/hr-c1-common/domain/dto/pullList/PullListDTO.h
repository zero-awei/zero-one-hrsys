#pragma once
#ifndef _PullList_DTO_
#define _PullList_DTO_
#include "../../GlobalInclude.h"
#include <domain/query/auditstatusQuery/auditstatusQuery.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ItemDTO : public oatpp::DTO
{
	DTO_INIT(ItemDTO, DTO);
	// 列表项代号
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("common.dto.code");
	}
	DTO_FIELD(UInt32, key);
	// 对应值
	DTO_FIELD_INFO(val) {
		info->description = ZH_WORDS_GETTER("common.dto.value");
	}
	DTO_FIELD(String, val);

public:
	ItemDTO()
	{
		key = 1;
		val = "否";
	}

	ItemDTO(Int32 k, String v)
	{
		key = k;
		val = v;
	}
};

/**
 * 组装下拉列表项到List
 * 负责人：fengchu
 */
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, DTO);
	DTO_FIELD_INFO(pullList) {
		info->description = ZH_WORDS_GETTER("common.dto.list");
	}
	DTO_FIELD(List<T>, pullList) = {};
};

class PullListDTO : public ListDTO<ItemDTO::Wrapper>
{
	DTO_INIT(PullListDTO, ListDTO<ItemDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PULLLISTDTO_H_



