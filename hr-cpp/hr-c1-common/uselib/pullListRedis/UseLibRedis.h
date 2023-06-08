#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:15:36
 
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
#ifndef _TESTREDIS_H_
#define _TESTREDIS_H_

#include <unordered_map>
#include <string>

/**
 * 下拉列表Redis
 * 参考链接：https://github.com/sewenew/redis-plus-plus
 */
class UseLibRedis
{
public:
	// Redis 查询
	static std::unordered_map<std::string, std::string> queryRedis(const std::string &key);

	// Redis 针对特定表(tablename)新增
	static void updateRedisWithTable(const std::unordered_map<std::string, std::string>& m, std::string tablename);

	static void updateRedis(const std::string &key, const std::unordered_map<std::string, std::string>& m);

};
#endif // _TESTREDIS_H_
