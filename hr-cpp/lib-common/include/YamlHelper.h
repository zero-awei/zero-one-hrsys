#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 16:19:31

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
#ifndef _YAMLHELPER_H_
#define _YAMLHELPER_H_
#include "yaml-cpp/yaml.h"

class YamlHelper final
{
public:
	//************************************
	// Method:    getString
	// FullName:  YamlCpp::getString
	// Access:    public 
	// Returns:   std::string
	// Qualifier: 以Properties风格读取Yaml配置对应的字符串
	// Parameter: YAML::Node * node 数据节点
	// Parameter: const std::string & key 数据的key，如spring.datasource.url
	//************************************
	std::string getString(YAML::Node* node, const std::string& key);

	//************************************
	// Method:    parseDbConnUrl
	// FullName:  YamlHelper::parseDbConnUrl
	// Access:    public 
	// Returns:   void
	// Qualifier: 解析数据库连接字符串获取数据库相关信息
	// Parameter: const std::string& url 数据库连接字符串
	// Parameter: std::string * ip 保存IP
	// Parameter: int * port 保存端口
	// Parameter: std::string * dbname 保存数据库名称
	//************************************
	void parseDbConnUrl(const std::string& url, std::string* ip, int* port, std::string* dbname);
};
#endif // _YAMLHELPER_H_
