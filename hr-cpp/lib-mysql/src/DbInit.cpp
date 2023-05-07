/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:11:03
 
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
#include "../include/DbInit.h"
#include <sstream>

ConnPool* DbInit::connPool = NULL;

bool DbInit::initDbPool(DBConfig config)
{
	releasePool();
	stringstream ss;
	ss << "tcp://" << config.host << ":" << config.port << "/" << config.db;
	connPool = new ConnPool(ss.str(), config.user, config.pass, config.poolMaxSize);

	// 测试获取连接对象
	auto testConn = connPool->GetConnection();
	if (testConn)
	{
		cout << "mysql connection pool init finish." << endl;
		connPool->ReleaseConnection(testConn);
		return true;
	}
	else
	{
		cout << "mysql connection pool init fail, please check your connection info." << endl;
		return false;
	}
}

ConnPool* DbInit::getConnPool()
{
	return connPool;
}

void DbInit::releasePool()
{
	if (connPool) {
		delete connPool;
		connPool = nullptr;
		cout << "mysql connection pool release finish." << endl;
	}
}
