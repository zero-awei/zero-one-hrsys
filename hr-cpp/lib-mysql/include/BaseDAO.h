#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:10
 
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
#ifndef _ABSTRACT_DAO_
#define _ABSTRACT_DAO_
#include "SqlSession.h"

/**
 * 定义一个基础的DAO类，方便管理，后续定义DAO都需要继承它
 */
class BaseDAO
{
private:
	// 是否自动释放SQLSession
	bool isAutoRelease;
protected:
	// 定义一个SqlSession
	SqlSession* sqlSession;
public:
	BaseDAO();
	virtual ~BaseDAO();
	// 获取SqlSession
	SqlSession* getSqlSession();
	// 设置SqlSession
	void setSqlSession(SqlSession* session);
	// 设置是否自动释放SqlSession
	void setAutoRelease(bool release);
};

#endif // !_ABSTRACT_DAO_
