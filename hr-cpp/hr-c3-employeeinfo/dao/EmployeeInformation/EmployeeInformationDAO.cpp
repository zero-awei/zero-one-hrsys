/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 22:04:02

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "EmployeeInformationDAO.h"
#include "EmployeeInformationMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}\
if (query->organize) { \
	sql << " AND organize=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->organize.getValue("")); \
}\
if (query->depart) { \
	sql << " AND depart=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->depart.getValue("")); \
}\
if (query->depart) { \
	sql << " AND depart=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->depart.getValue("")); \
}\
if (query->job) { \
	sql << " AND job=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->job.getValue("")); \
}\
if (query->post) { \
	sql << " AND post=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->post.getValue("")); \
}\
if (query->idMum) { \
	sql << " AND idMum=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idMum.getValue("")); \
}\
if (query->birthday) { \
	sql << " AND birthday=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->birthday.getValue("")); \
}\
if (query->phone) { \
	sql << " AND phone=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue("")); \
}\
if (query->state) { \
	sql << " AND state=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue("")); \
}


// 统计数据条数
uint64_t EmployeeInformationDAO::count(const EmployeeInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// 分页查询数据
std::list<EmployeeInformationPageDO> EmployeeInformationDAO::selectWithPage(const EmployeeInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EmployeeInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EmployeeInformationPageDO, EmployeeInformationMapper>(sqlStr, mapper, params);
}
// 插入数据
uint64_t EmployeeInformationDAO::insert(const EmployeeInformationPageDO& iObj)
{

	string sql= "INSERT INTO `sample` (`name`,`age`,`id`,`organize`,`depart`,`job`,`post`,`idMum`,`birthday`,`phone`,`state`,) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql,"%s&i%s%s%s%s%s%s%s%s%s",iObj.getName(),iObj.getAge(),iObj.getId(),iObj.getOrganize(),iObj.getDepart(),iObj.getJob(), iObj.getPost(),iObj.getIdMum(),iObj.getBirthday(),iObj.getPhone(),iObj.getState());
}
