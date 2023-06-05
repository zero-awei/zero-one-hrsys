/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/20 19:45:08
*/
#ifndef _EDUCATIONDELETEDTO_H_
#define _EDUCATIONDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 删除：根据教育信息的主键PIMEDUCATIONID删除数据
*/
class EducationDeleteSingleDTO : public oatpp::DTO
{
	DTO_INIT(EducationDeleteSingleDTO, DTO);
	// 教育信息标识 （必填）
	DTO_FIELD(List<String>, PIMEDUCATIONID);
	DTO_FIELD_INFO(PIMEDUCATIONID) {
		info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
	}

	//// 外键：pimpersonid
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	//}



};

/*
* 多条删除
*/
//class EducationDeleteNotSingleDTO : public oatpp::DTO
//{
//	DTO_INIT(EducationDeleteNotSingleDTO, DTO);
//	// 多条教育信息
//	DTO_FIELD(oatpp::List<String>, deleteIds);
//	DTO_FIELD_INFO(deleteIds) {
//		info->description = ZH_WORDS_GETTER("deleteIds");
//	}
//
//};




#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONDELETEDTO_H_#pragma once
