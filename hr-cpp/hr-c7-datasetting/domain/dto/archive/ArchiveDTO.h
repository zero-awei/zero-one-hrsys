#pragma once
#ifndef _ARCHIVEDTO_H_
#define _ARCHIVEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个可修改档案室信息的传输对象
 */
class ArchiveDTO : public oatpp::DTO
{
	DTO_INIT(ArchiveDTO, DTO);
	// 排序号
	DTO_FIELD(Int32, sortID);
	DTO_FIELD_INFO(sortID) {
		info->description = ZH_WORDS_GETTER("archive.field.sortID");
	}
	// 档案室名称
	DTO_FIELD(String,archiveName);
	DTO_FIELD_INFO(archiveName) {
		info->description = ZH_WORDS_GETTER("archive.field.archiveName");
	}
	// 柜号
	DTO_FIELD(Int32, cabinetNum);
	DTO_FIELD_INFO(cabinetNum) {
		info->description = ZH_WORDS_GETTER("archive.field.cabinetNum");
	}
	//层号
	DTO_FIELD(Int32, layerNum);
	DTO_FIELD_INFO(layerNum) {
		info->description = ZH_WORDS_GETTER("archive.field.layerNum");
	}
	//编号
	DTO_FIELD(Int32, numID);
	DTO_FIELD_INFO(numID) {
		info->description = ZH_WORDS_GETTER("archive.field.numID");
	}
};

/**
 * 定义一个档案室信息分页传输对象
 */
class ArchivePageDTO : public PageDTO<ArchiveDTO::Wrapper>
{
	DTO_INIT(ArchivePageDTO, PageDTO<ArchiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_