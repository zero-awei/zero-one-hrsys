/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/17 21:33:02
*/
#ifndef _EDUCATION_H_
#define _EDUCATION_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 教育信息传输对象
*/


class EducationSingleDTO : public oatpp::DTO
{
	DTO_INIT(EducationSingleDTO, DTO);
	// 教育信息标识 （必填）
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
	//// 外键：pimpersonid
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	//}



	//// 教育名称
	//DTO_FIELD(String, JYMC);
	//DTO_FIELD_INFO(JYMC) {
	//	info->description = ZH_WORDS_GETTER("education.JYMC");
	//}


	//// 建立人
	//DTO_FIELD(String, CREATEMAN);
	//DTO_FIELD_INFO(CREATEMAN) {
	//	info->description = ZH_WORDS_GETTER("education.CREATEMAN");
	//}

	//// 教育信息名称
	//DTO_FIELD(String, PIMEDUCATIONNAME);
	//DTO_FIELD_INFO(PIMEDUCATIONNAME) {
	//	info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONNAME");
	//}

	//// 更新人
	//DTO_FIELD(String, UPDATEMAN);
	//DTO_FIELD_INFO(UPDATEMAN) {
	//	info->description = ZH_WORDS_GETTER("education.UPDATEMAN");
	//}

	//// 更新时间
	//DTO_FIELD(UInt64, UPDATEDATE);
	//DTO_FIELD_INFO(UPDATEDATE) {
	//	info->description = ZH_WORDS_GETTER("education.UPDATEDATE");
	//}

	//// 建立时间
	//DTO_FIELD(Int64, CREATEDATE);
	//DTO_FIELD_INFO(CREATEDATE) {
	//	info->description = ZH_WORDS_GETTER("education.CREATEDATE");
	//}

	//// 人员信息标识
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	//}
	//// 记录所属
	//DTO_FIELD(String, JLSS);
	//DTO_FIELD_INFO(JLSS) {
	//	info->description = ZH_WORDS_GETTER("education.JLSS");
	//}
	//// 记录管理编号
	//DTO_FIELD(String, JLGLBH);
	//DTO_FIELD_INFO(JLGLBH) {
	//	info->description = ZH_WORDS_GETTER("education.JLGLBH");
	//}
	//// 记录审批状态
	//DTO_FIELD(String, JLSPZT);
	//DTO_FIELD_INFO(JLSPZT) {
	//	info->description = ZH_WORDS_GETTER("education.JLSPZT");
	//}
	//// 记录操作者
	//DTO_FIELD(String, JLCZZ);
	//DTO_FIELD_INFO(JLCZZ) {
	//	info->description = ZH_WORDS_GETTER("education.JLCZZ");
	//}
	//// 部门标识
	//DTO_FIELD(String, ORMORGSECTORID);
	//DTO_FIELD_INFO(ORMORGSECTORID) {
	//	info->description = ZH_WORDS_GETTER("education.ORMORGSECTORID");
	//}
	//// 学位
	//DTO_FIELD(String, DEGREE);
	//DTO_FIELD_INFO(DEGREE) {
	//	info->description = ZH_WORDS_GETTER("education.DEGREE");
	//}
	//// 员工编号
	//DTO_FIELD(String, YGBH);
	//DTO_FIELD_INFO(YGBH) {
	//	info->description = ZH_WORDS_GETTER("education.YGBH");
	//}
	//// 参加工作时间
	//DTO_FIELD(UInt64, CJGZSJ);
	//DTO_FIELD_INFO(CJGZSJ) {
	//	info->description = ZH_WORDS_GETTER("education.CJGZSJ");
	//}
	//// 建筑系统工作时间
	//DTO_FIELD(UInt64, TOZJDATE);
	//DTO_FIELD_INFO(TOZJDATE) {
	//	info->description = ZH_WORDS_GETTER("education.TOZJDATE");
	//}
	//// 局工作时间
	//DTO_FIELD(UInt64, DZJBJSJ);
	//DTO_FIELD_INFO(DZJBJSJ) {
	//	info->description = ZH_WORDS_GETTER("education.DZJBJSJ");
	//}
	//// 本单位工作时间
	//DTO_FIELD(UInt64, DBDWSJ);
	//DTO_FIELD_INFO(DBDWSJ) {
	//	info->description = ZH_WORDS_GETTER("education.DBDWSJ");
	//}
	//// 拒绝原因
	//DTO_FIELD(String, REASON);
	//DTO_FIELD_INFO(REASON) {
	//	info->description = ZH_WORDS_GETTER("education.REASON");
	//}

	

};

/**
 * 教育信息分页传输对象
 */
class EducationPageDTO : public PageDTO<EducationSingleDTO::Wrapper>
{
	DTO_INIT(EducationPageDTO, PageDTO<EducationSingleDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATION_H_#pragma once
