#pragma once
#ifndef _ARVHIVES_QUERY_
#define _ARVHIVES_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ArchivesQuery : public PageQuery
{
	DTO_INIT(ArchivesQuery, PageQuery);

	//字段注释，表名，字段在表中的列数	
	//档案信息标识，t_pimarchives, 1
	DTO_FIELD(String, pimArchivesId);
	DTO_FIELD_INFO(pimArchivesId) {
		info->description = ZH_WORDS_GETTER("archives.newField.pimArchivesId");
	}

	// 档案编号，t_pimarchives, 8
	DTO_FIELD(String, dabh);
	DTO_FIELD_INFO(dabh) {
		info->description = ZH_WORDS_GETTER("archives.newField.dabh");
	}

	// 管理单位，t_srforg，7
	DTO_FIELD(String, orgName);
	DTO_FIELD_INFO(orgName) {
		info->description = ZH_WORDS_GETTER("archives.newField.orgName");
	}

	// 档案保管地，t_pimarchives, 10
	DTO_FIELD(String, dabgd);
	DTO_FIELD_INFO(dabgd) {
		info->description = ZH_WORDS_GETTER("archives.newField.dabgd");
	}

	// 档案室，t_archivescenter, 2
	DTO_FIELD(String, archivesCenterName);
	DTO_FIELD_INFO(archivesCenterName) {
		info->description = ZH_WORDS_GETTER("archives.newField.archivesCenterName");
	}

	// 档案状态，t_pimarchives, 9
	DTO_FIELD(String, dazt);
	DTO_FIELD_INFO(dazt) {
		info->description = ZH_WORDS_GETTER("archives.newField.dazt");
	}

	// 员工编号，t_pimperson, 8
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("archives.newField.ygbh");
	}

	// 员工姓名，t_pimperson, 3
	DTO_FIELD(String, pimPersonName);
	DTO_FIELD_INFO(pimPersonName) {
		info->description = ZH_WORDS_GETTER("archives.newField.pimPersonName");
	}

	// 员工状态, t_pimperson, 35
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("archives.newField.ygzt");
	}

	// 所属单位, t_pimarchives, 30
	DTO_FIELD(String, ormOrgName);
	DTO_FIELD_INFO(ormOrgName) {
		info->description = ZH_WORDS_GETTER("archives.newField.ormOrgName");
	}

	//档案未转出月数

	// 档案借阅状态, t_pimarchives
	DTO_FIELD(String, zt);
	DTO_FIELD_INFO(zt) {
		info->description = ZH_WORDS_GETTER("archives.newField.zt");
	}

	//-----------下面是详细查询以及新增需要用到的字段-----------------

	// 档案借阅状态, t_pimarchives
	DTO_FIELD(String, education);
	DTO_FIELD_INFO(education) {
		info->description = ZH_WORDS_GETTER("archives.newField.education");
	}

	// 档案出生时间, t_pimarchives
	DTO_FIELD(String, dateOfBirth);
	DTO_FIELD_INFO(dateOfBirth) {
		info->description = ZH_WORDS_GETTER("archives.newField.dateOfBirth");
	}

	// 档案入党时间, t_pimarchives
	DTO_FIELD(String, joinPartyDate);
	DTO_FIELD_INFO(joinPartyDate) {
		info->description = ZH_WORDS_GETTER("archives.newField.joinPartyDate");
	}

	// 添加工作时间, t_pimarchives
	DTO_FIELD(String, startWorkDatae);
	DTO_FIELD_INFO(startWorkDatae) {
		info->description = ZH_WORDS_GETTER("archives.newField.startWorkDatae");
	}
	//-------------外键的唯一标识----------------
	// 唯一标识（外键）, t_pimperson
	DTO_FIELD(String, pimPersonId);
	DTO_FIELD_INFO(pimPersonId) {
		info->description = ZH_WORDS_GETTER("archives.newField.pimPersonId");
	}
	// 唯一标识（外键）, t_srforg
	DTO_FIELD(String, orMorGId3);
	DTO_FIELD_INFO(orMorGId3) {
		info->description = ZH_WORDS_GETTER("archives.newField.orMorGId3");
	}
	// 唯一标识（外键）, t_archivescenter
	DTO_FIELD(String, archivesCenterId);
	DTO_FIELD_INFO(archivesCenterId) {
		info->description = ZH_WORDS_GETTER("archives.newField.archivesCenterId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_