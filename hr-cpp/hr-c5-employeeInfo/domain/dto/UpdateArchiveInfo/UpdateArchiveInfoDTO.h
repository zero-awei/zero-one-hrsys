#pragma once
#pragma once
#ifndef _UPDATE_ARCHIVE_INFO_DTO_
#define _UPDATE_ARCHIVE_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//档案管理传输对象
class UpdateArchiveInfoDTO : public oatpp::DTO {
	DTO_INIT(UpdateArchiveInfoDTO, DTO);
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
	//是否新建档
	DTO_FIELD(String, sfxjd);
	DTO_FIELD_INFO(sfxjd) {
		info->description = ZH_WORDS_GETTER("archive.dto.sfxjd");
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
	//所属单位
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("archive.dto.ormorgname");
	}
	//档案学历
	DTO_FIELD(String, education);
	DTO_FIELD_INFO(education) {
		info->description = ZH_WORDS_GETTER("archive.dto.education");
	}
	//档案出生日期
	DTO_FIELD(String, dateofbirth);
	DTO_FIELD_INFO(dateofbirth) {
		info->description = ZH_WORDS_GETTER("archive.dto.dateofbirth");
	}
	// 档案入党时间
	DTO_FIELD(String, joinpartydate);
	DTO_FIELD_INFO(joinpartydate) {
		info->description = ZH_WORDS_GETTER("archive.dto.joinpartydate");
	}
	// 档案参加工作时间
	DTO_FIELD(String, startworkdate);
	DTO_FIELD_INFO(startworkdate) {
		info->description = ZH_WORDS_GETTER("archive.dto.startworkdate");
	}
	// 档案状态
	DTO_FIELD(String, dastate);
	DTO_FIELD_INFO(dastate) {
		info->description = ZH_WORDS_GETTER("archive.dto.dastate");
	}
	//备注
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("archive.dto.bz");
	}
	//附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("archive.dto.fj");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATE_ARCHIVE_INFO_DTO_