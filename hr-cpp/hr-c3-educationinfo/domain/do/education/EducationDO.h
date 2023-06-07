/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/24 16:04:19
*/
#ifndef _EDUCATIONDO_H_
#define _EDUCATIONDO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationDO
{	
	// 教育信息标识 （必填）
	CC_SYNTHESIZE(string, PIMEDUCATIONID, FunPIMEDUCATIONID);

	// 学历
	CC_SYNTHESIZE(string, XL, FunXL);

	// 入学时间
	//CC_SYNTHESIZE(uint64_t, QSSJ, FunQSSJ);
	CC_SYNTHESIZE(string, QSSJ, FunQSSJ);
	
	// 毕业时间
	//CC_SYNTHESIZE(uint64_t, JSSJ, FunJSSJ);
	CC_SYNTHESIZE(string, JSSJ, FunJSSJ);

	// 毕业院校
	CC_SYNTHESIZE(string, BYYX, FunBYYX);

	// 一级学科
	CC_SYNTHESIZE(string, XKML, FunXKML);

	// 所学专业
	CC_SYNTHESIZE(string, SXZY, FunSXZY);


	// 学习形式
	CC_SYNTHESIZE(string, XLLX, FunXLLX);

	// 学校性质
	CC_SYNTHESIZE(string, XXXZ, FunXXXZ);

	// 是否第一学历
	CC_SYNTHESIZE(uint64_t, SFDYXL, FunSFDYXL);


	//是否最高学历
	CC_SYNTHESIZE(uint64_t, SFZGXL, FunSFZGXL);

	// 毕业证
	CC_SYNTHESIZE(string, BTZ, FunBTZ);
	
	// 学位证
	CC_SYNTHESIZE(string, XWZ, FunXWZ);
	
	// 学历验证
	CC_SYNTHESIZE(string, XLCX, FunXLCX);

	// 其他附件
	CC_SYNTHESIZE(string, FJ, FunFJ);

	// 人员id
	CC_SYNTHESIZE(string, PIMPERSONID, FunPIMPERSONID);

public:
	EducationDO() {
		PIMEDUCATIONID = "";
		XL = "";
		QSSJ = "";
		JSSJ = "";
		BYYX = "";

		XKML = "";
		SXZY = "";
		XLLX = "";
		XXXZ = "";
		SFDYXL = 1;

		SFZGXL = 1;
		BTZ = "";
		XWZ = "";
		XLCX = "";
		FJ = "";
		PIMPERSONID = "";
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONDO_H_#pragma once
