#pragma once
#ifndef _QUALIFICATIONDTO_H_
#define _QUALIFICATIONDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
  定义一个可修改执业资格证书信息的传输对象
*/

class QualificationDTO : public oatpp::DTO
{
	DTO_INIT(QualificationDTO, DTO);
	// 执业资格专业编码
	DTO_FIELD(String, pimqualmajorid);
	DTO_FIELD_INFO(pimqualmajorid) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorid");
	}
	// 级别
	DTO_FIELD(String, qualevel);
	DTO_FIELD_INFO(qualevel) {
		info->description = ZH_WORDS_GETTER("archive.field.qualevel");
	}
	// 执业资格
	DTO_FIELD(String, pimqualmajorname);
	DTO_FIELD_INFO(pimqualmajorname) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorname");
	}
	//专业
	DTO_FIELD(String, quamajor);
	DTO_FIELD_INFO(quamajor) {
		info->description = ZH_WORDS_GETTER("archive.field.quamajor");
	}
};
/**
 * 定义一个执业资格证书信息分页传输对象
 */
class QualificationPageDTO : public PageDTO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationPageDTO, PageDTO<QualificationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_QUALIFICATIONDTO_H_