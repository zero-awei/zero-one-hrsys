#pragma once
#ifndef _ARCHIVES_DTO_
#define _ARCHIVES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 档案信息传输对象
 */
class ArchivesDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesDTO, DTO);

	// 档案编号，
	DTO_FIELD(String, archivesNo);
	DTO_FIELD_INFO(archivesNo) {
		info->description = ZH_WORDS_GETTER("dto.field.archivesNo");
	}

	// 管理单位，
	DTO_FIELD(String, managementUnits);
	DTO_FIELD_INFO(managementUnits) {
		info->description = ZH_WORDS_GETTER("dto.field.managementUnits");
	}

	// 档案保管地，
	DTO_FIELD(String, DABGD);
	DTO_FIELD_INFO(DABGD) {
		info->description = ZH_WORDS_GETTER("dto.field.DABGD");
	}

	// 档案室，
	DTO_FIELD(String, archivesCenterName);
	DTO_FIELD_INFO(archivesCenterName) {
		info->description = ZH_WORDS_GETTER("dto.field.archivesCenterName");
	}

	// 员工编号，
	DTO_FIELD(String, YGBH);
	DTO_FIELD_INFO(YGBH) {
		info->description = ZH_WORDS_GETTER("dto.field.YGBH");
	}

	// 员工姓名，
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("dto.field.PimPersonName");
	}

	// 员工状态
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("dto.field.ygzt");
	}

	// 所属单位，
	DTO_FIELD(String, ORMORGName);
	DTO_FIELD_INFO(ORMORGName) {
		info->description = ZH_WORDS_GETTER("dto.field.ORMORGName");
	}

	// 档案状态，
	DTO_FIELD(String, DAZT);
	DTO_FIELD_INFO(DAZT) {
		info->description = ZH_WORDS_GETTER("dto.field.DAZT");
	}
};

/**
 * 档案信息分页传输对象
 */
class ArchivesPageDTO : public PageDTO<ArchivesDTO::Wrapper>
{
	DTO_INIT(ArchivesPageDTO, PageDTO<ArchivesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif