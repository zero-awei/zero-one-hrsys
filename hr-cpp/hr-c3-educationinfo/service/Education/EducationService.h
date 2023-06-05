/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:01:46
*/
#ifndef _EDUCATIONSERVICE_H_
#define _EDUCATIONSERVICE_H_

#include "domain/dto/education/EducationDTO.h"
#include "domain/query/educationPage/EducationPageQuery.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "domain/dto/educationDelete/EducationDeleteDTO.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"
class EducationService 
{
public:
	/**
	 * 分页查询指定员工教育信息
	 * 负责人：chen jun
	 */
	EducationPageDTO::Wrapper listEducationPage(const EducationPageQuery::Wrapper& query);
	/**
	 * 单独查询指定员工教育信息
	 * 负责人：chen jun
	 */
	EducationSingleDTO::Wrapper listEducationSingle(const EducationSingleQuery::Wrapper& query);
	/**
	 * 添加指定员工教育信息
	 * 负责人：chen jun
	 */
	int saveEducation(const EducationAddDTO::Wrapper& dto);
	/**
	 * 修改
	 * 负责人：Chen jun
	 */
	bool updateEducation(const EducationAddDTO::Wrapper& dto);
	/**
	* 删除单条
	* 负责人 : Chen jun
	*/
	bool removeEducation(const EducationDeleteSingleDTO::Wrapper& dto);
	/**
	* 删除多条
	* 负责人 : Chen jun
	*/
	//bool removeEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto);
};



#endif // !_EDUCATIONSERVICE_H_#pragma once




