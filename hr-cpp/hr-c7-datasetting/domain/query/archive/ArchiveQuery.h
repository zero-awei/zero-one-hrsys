#ifndef _ARCHIVEQUERY_
#define _ARCHIVEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例档案室查询对象
 */
class ArchiveQuery : public PageQuery
{
	DTO_INIT(ArchiveQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, ArchiveName);
	DTO_FIELD_INFO(ArchiveName) {
		info->description = ZH_WORDS_GETTER("archive.field.ArchiveName");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif //

