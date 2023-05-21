#pragma once
#ifndef _NOT_IN_ARCHIVE_DTO_
#define _NOT_IN_ARCHIVE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//档案管理传输对象
class NotInArchiveDTO : public oatpp::DTO {
	DTO_INIT(NotInArchiveDTO, DTO);
	//档案编号
	DTO_FIELD(String, dabh);
	DTO_FIELD_INFO(dabh) {
		info->description = ZH_WORDS_GETTER("archive.dto.dabh");
	}
	//管理单位
 	DTO_FIELD(String, gldw);
	DTO_FIELD_INFO(gldw) {
		info->description = ZH_WORDS_GETTER("archive.dto.gldw");
	}
	//档案保管地
	DTO_FIELD(String, bgd);
	DTO_FIELD_INFO(bgd) {
		info->description = ZH_WORDS_GETTER("archive.dto.dabgd");
	}
	//档案室
	DTO_FIELD(String, archivescentername);
	DTO_FIELD_INFO(archivescentername) {
		info->description = ZH_WORDS_GETTER("archive.dto.archivescentername");
	}
	//档案状态
	DTO_FIELD(String, dastate);
	DTO_FIELD_INFO(dastate) {
		info->description = ZH_WORDS_GETTER("archive.dto.dastate");
	}
	//员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygbh");
	}
	//员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimpersonname");
	}
	//操作列
	DTO_FIELD(String, operat);
	DTO_FIELD_INFO(operat) {
		info->description = ZH_WORDS_GETTER("archive.dto.operat");
	}
};
//档案管理分页传输对象
class NotInArchivePageDTO : public PageDTO<NotInArchiveDTO::Wrapper>
{
	DTO_INIT(NotInArchivePageDTO, PageDTO<NotInArchiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NOT_IN_ARCHIVE_DTO_