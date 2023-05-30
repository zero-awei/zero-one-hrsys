#pragma once
#ifndef _QUALIFICATIONDTO_H_
#define _QUALIFICATIONDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
  证书查询传输数据类型
*/

class QualificationDTO : public oatpp::DTO
{
public:
	QualificationDTO() {};
	DTO_INIT(QualificationDTO, DTO);
	//级别
	API_DTO_FIELD_DEFAULT(String, qualevel, ZH_WORDS_GETTER("qualification.field.qualevel"));
	//执业资格
	API_DTO_FIELD_DEFAULT(String, pimqualmajorname, ZH_WORDS_GETTER("qualification.field.pimqualmajorname"));
	//专业
	API_DTO_FIELD_DEFAULT(String, quamajor, ZH_WORDS_GETTER("qualification.field.quamajor"));

};
/*
  证书查询分页传输数据类型
*/
class QualificationPageDTO : public PageDTO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationPageDTO, PageDTO<QualificationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_qualificationDTO_H_