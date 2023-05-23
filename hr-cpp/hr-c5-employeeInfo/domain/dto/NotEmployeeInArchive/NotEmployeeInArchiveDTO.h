#pragma once
#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_DTO_
#define _NOT_EMPLOYEE_IN_ARCHIVE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//档案管理传输对象
class NotEmployeeInArchiveDTO : public oatpp::DTO {
	DTO_INIT(NotEmployeeInArchiveDTO, DTO);
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
	DTO_FIELD(String, dazt);
	DTO_FIELD_INFO(dazt) {
		info->description = ZH_WORDS_GETTER("archive.dto.dazt");
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
	//员工状态
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygzt");
	}
	//操作列
	DTO_FIELD(String, operat);
	DTO_FIELD_INFO(operat) {
		info->description = ZH_WORDS_GETTER("archive.dto.operat");
	}
	//备注
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("archive.dto.bz");
	}
	//建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("archive.dto.createdate");
	}
	//建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("archive.dto.createman");
	}
	//档案调入日期
	DTO_FIELD(String, daddrq);
	DTO_FIELD_INFO(daddrq) {
		info->description = ZH_WORDS_GETTER("archive.dto.daddrq");
	}
	//调出单位
	DTO_FIELD(String, dcdw);
	DTO_FIELD_INFO(dcdw) {
		info->description = ZH_WORDS_GETTER("archive.dto.dcdw");
	}
	//调入单位
	DTO_FIELD(String, drdw);
	DTO_FIELD_INFO(drdw) {
		info->description = ZH_WORDS_GETTER("archive.dto.drdw");
	}
	//调档记录类型
	DTO_FIELD(String, ddjltype);
	DTO_FIELD_INFO(ddjltype) {
		info->description = ZH_WORDS_GETTER("archive.dto.ddjltype");
	}
	//档案归档地变更记录标识
	DTO_FIELD(String, pimarchiveschangeid);
	DTO_FIELD_INFO(pimarchiveschangeid) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimarchiveschangeid");
	}
	//档案信息标识
	DTO_FIELD(String, pimarchivesid);
	DTO_FIELD_INFO(pimarchivesid) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimarchivesid");
	}
	//更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("archive.dto.updatedate");
	}
	//更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("archive.dto.updateman");
	}
};
//档案管理分页传输对象
class NotEmployeeInArchivePageDTO : public PageDTO<NotEmployeeInArchiveDTO::Wrapper>
{
	DTO_INIT(NotEmployeeInArchivePageDTO, PageDTO<NotEmployeeInArchiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_DTO_