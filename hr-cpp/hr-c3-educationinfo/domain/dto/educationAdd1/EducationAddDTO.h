/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/31 0:04:18
*/
#ifndef _EDUCATIONADDDTO_H_
#define _EDUCATIONADDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationAddDTO : public oatpp::DTO
{
	DTO_INIT(EducationAddDTO, DTO);
	
	// 教育信息标识 （必填）              后台生成
	DTO_FIELD(String, PIMEDUCATIONID);
	DTO_FIELD_INFO(PIMEDUCATIONID) {
		info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
	}
	// 学历
	DTO_FIELD(String, XL);
	DTO_FIELD_INFO(XL) {
		info->description = ZH_WORDS_GETTER("education.XL");
	}
	// 入学时间
	//DTO_FIELD(UInt64, QSSJ);
	DTO_FIELD(String, QSSJ);
	DTO_FIELD_INFO(QSSJ) {
		info->description = ZH_WORDS_GETTER("education.QSSJ");
	}
	// 毕业时间
	//DTO_FIELD(UInt64, JSSJ);
	DTO_FIELD(String, JSSJ);
	DTO_FIELD_INFO(JSSJ) {
		info->description = ZH_WORDS_GETTER("education.JSSJ");
	}
	// 毕业院校
	DTO_FIELD(String, BYYX);
	DTO_FIELD_INFO(BYYX) {
		info->description = ZH_WORDS_GETTER("education.BYYX");
	}
	// 一级学科
	DTO_FIELD(String, XKML);
	DTO_FIELD_INFO(XKML) {
		info->description = ZH_WORDS_GETTER("education.XKML");
	}
	// 所学专业
	DTO_FIELD(String, SXZY);
	DTO_FIELD_INFO(SXZY) {
		info->description = ZH_WORDS_GETTER("education.SXZY");
	}
	// 学习形式
	DTO_FIELD(String, XLLX);
	DTO_FIELD_INFO(XLLX) {
		info->description = ZH_WORDS_GETTER("education.XLLX");
	}
	// 学校性质
	DTO_FIELD(String, XXXZ);
	DTO_FIELD_INFO(XXXZ) {
		info->description = ZH_WORDS_GETTER("education.XXXZ");
	}
	// 是否第一学历
	DTO_FIELD(UInt64, SFDYXL);
	DTO_FIELD_INFO(SFDYXL) {
		info->description = ZH_WORDS_GETTER("education.SFDYXL");
	}
	//是否最高学历
	DTO_FIELD(UInt64, SFZGXL);
	DTO_FIELD_INFO(SFZGXL) {
		info->description = ZH_WORDS_GETTER("education.SFZGXL");
	}
	// 毕业证
	DTO_FIELD(String, BTZ);
	DTO_FIELD_INFO(BTZ) {
		info->description = ZH_WORDS_GETTER("education.BTZ");
	}
	// 学位证
	DTO_FIELD(String, XWZ);
	DTO_FIELD_INFO(XWZ) {
		info->description = ZH_WORDS_GETTER("education.XWZ");
	}
	// 学历验证
	DTO_FIELD(String, XLCX);
	DTO_FIELD_INFO(XLCX) {
		info->description = ZH_WORDS_GETTER("education.XLCX");
	}
	// 其他附件
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("education.FJ");
	}

	// 外键：pimpersonid
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONADDDTO_H_#pragma once
