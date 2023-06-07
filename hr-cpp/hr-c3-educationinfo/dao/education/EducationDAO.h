/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:12:37
*/
#ifndef _EDUCATIONDAO_H_
#define _EDUCATIONDAO_H_
#include "BaseDAO.h"
#include "domain/do/education/EducationDO.h"
#include "domain/query/educationPage/EducationPageQuery.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "domain/dto/education/EducationDTO.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"

class EducationDAO : public BaseDAO
{
public:
	//功能1 ：分页查询教育信息DAO实现
	std::list<EducationDO> selectEducationPage(const EducationPageQuery::Wrapper& query);
	uint64_t count(const EducationPageQuery::Wrapper& query);

	//功能2 ：单独查询教育信息DAO实现
	list<EducationDO> selectEducationSingle(const EducationSingleQuery::Wrapper& query);

	//功能3 ：单独插入教育信息DAO实现
	int insertEducation(const EducationDO& iObj);

	//功能4 ：单独修改教育信息DAO实现
	bool updateEducaiton(const EducationDO& data);

	//功能5 ：单条删除教育信息DAO实现
	int deleteEducaiton(std::string id);

	//功能6 ：多条删除教育信息DAO实现
	//int deleteEducaitonNotSingle(string id);

};

#endif // !_EDUCATIONDAO_H_