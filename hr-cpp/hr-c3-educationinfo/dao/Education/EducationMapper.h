/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:38:26
*/
#ifndef _EDUCATIONMAPPER_H_
#define _EDUCATIONMAPPER_H_
#include "BaseDAO.h"
#include "Mapper.h"
#include "domain/do/Education/EducationDO.h"

class EducationMapper : public Mapper<EducationDO>
{
public:
	EducationDO mapper(ResultSet* resultSet) const override
	{
		EducationDO data;
		data.setFunPIMEDUCATIONID(resultSet->getString(1));	// 教育信息标识 （必填）
		data.setFunXL(resultSet->getString(2));	// 学历
		data.setFunQSSJ(resultSet->getUInt64(3));	// 入学时间
		data.setFunJSSJ(resultSet->getUInt64(4));	// 毕业时间
		data.setFunBYYX(resultSet->getString(5));	// 毕业院校
		data.setFunXKML(resultSet->getString(6));	// 	// 一级学科
		data.setFunSXZY(resultSet->getString(7));		// 所学专业
		data.setFunXLLX(resultSet->getString(8));	// 学习形式
		data.setFunXXXZ(resultSet->getString(9));	// 学校性质
		data.setFunSFDYXL(resultSet->getUInt64(10));		// 是否第一学历
		data.setFunSFZGXL(resultSet->getUInt64(11));		//是否最高学历
		data.setFunBTZ(resultSet->getString(12));		// 毕业证
		data.setFunXWZ(resultSet->getString(13));		// 学位证
		data.setFunXLCX(resultSet->getString(14));		// 学历验证
		data.setFunFJ(resultSet->getString(15));// 其他附件




		
		return data;
	}
};

#endif // !_EDUCATIONMAPPER_H_#pragma once

