#pragma once

#ifndef _SECTOR_QUERY_
#define _SECTOR_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SectorQuery : public PageQuery {
    DTO_INIT(SectorQuery, PageQuery);

    // ��ѯSector��parent��OrmOrg����OrmOrgsector
    API_DTO_FIELD_DEFAULT(String, parentdename, ZH_WORDS_GETTER("sectorquery.query.parentdename"));
    // ��ѯ��parent id
    API_DTO_FIELD_DEFAULT(String, parentkey, ZH_WORDS_GETTER("sectorquery.query.parentkey"));
    // ����ʽ
    DTO_FIELD(String, ssort);
	DTO_FIELD_INFO(ssort) {
		info->description = ZH_WORDS_GETTER("sectorquery.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SECTOR_QUERY_