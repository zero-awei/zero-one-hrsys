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
	DTO_FIELD(UInt64, sortid);
	DTO_FIELD_INFO(sortid) {
		info->description = ZH_WORDS_GETTER("archive.field.sortid");
	}
	// 档案室名称
	DTO_FIELD(String,archivename);
	DTO_FIELD_INFO(archivename) {
		info->description = ZH_WORDS_GETTER("archive.field.archivename");
	}
	// 柜号
	DTO_FIELD(Int32, cabinetnum);
	DTO_FIELD_INFO(cabinetnum) {
		info->description = ZH_WORDS_GETTER("archive.field.cabinetnum");
	}
	//层号
	DTO_FIELD(Int32, layernum);
	DTO_FIELD_INFO(layernum) {
		info->description = ZH_WORDS_GETTER("archive.field.layernum");
	}
	//编号
	DTO_FIELD(Int32, numid);
	DTO_FIELD_INFO(numid) {
		info->description = ZH_WORDS_GETTER("archive.field.numid");
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