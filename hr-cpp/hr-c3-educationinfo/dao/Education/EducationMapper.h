/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:38:26
*/
#ifndef _EDUCATIONMAPPER_H_
#define _EDUCATIONMAPPER_H_
#include "BaseDAO.h"
#include "Mapper.h"
#include "domain/do/education/EducationDO.h"

class EducationMapper : public Mapper<EducationDO>
{
public:
	EducationDO mapper(ResultSet* resultSet) const override
	{
		EducationDO data;
		data.setFunPIMEDUCATIONID(resultSet->getString(3));	// 教育信息标识 （主键）
		data.setFunXL(resultSet->getString(19));	// 学历
		data.setFunQSSJ(resultSet->getString(14));	// 入学时间
		data.setFunJSSJ(resultSet->getString(7));	// 毕业时间
		data.setFunBYYX(resultSet->getString(12));	// 毕业院校
		data.setFunXKML(resultSet->getString(37));	// 	// 一级学科
		data.setFunSXZY(resultSet->getString(6));		// 所学专业
		data.setFunXLLX(resultSet->getString(9));	// 学习形式
		data.setFunXXXZ(resultSet->getString(10));	// 学校性质
		data.setFunSFDYXL(resultSet->getUInt64(1));		// 是否第一学历
		data.setFunSFZGXL(resultSet->getUInt64(17));		//是否最高学历
		data.setFunBTZ(resultSet->getString(38));		// 毕业证
		data.setFunXWZ(resultSet->getString(39));		// 学位证
		data.setFunXLCX(resultSet->getString(40));		// 学历验证
		data.setFunFJ(resultSet->getString(19));// 其他附件
		data.setFunPIMPERSONID(resultSet->getString(20));// 外键
		return data;
	}
};

#endif // !_EDUCATIONMAPPER_H_#pragma once

