/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:10:04
 
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
#include "../include/BaseDAO.h"

BaseDAO::BaseDAO()
{
	isAutoRelease = true;
	sqlSession = new SqlSession();
}

BaseDAO::~BaseDAO()
{
	if (isAutoRelease && sqlSession) delete sqlSession;
}

SqlSession* BaseDAO::getSqlSession()
{
	return this->sqlSession;
}

void BaseDAO::setSqlSession(SqlSession* session)
{
	if(sqlSession)
		delete sqlSession;
	this->sqlSession = session;
}

void BaseDAO::setAutoRelease(bool release)
{
	this->isAutoRelease = release;
}
