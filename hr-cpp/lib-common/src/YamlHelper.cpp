/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 21:40:48

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
#include "pch.h"
#include "../include/YamlHelper.h"
#include "StringUtil.h"
#include <stack>

std::string YamlHelper::getString(YAML::Node* node, const std::string& key)
{
	//拆分Key
	vector<std::string> keys = StringUtil::split(key, ".");
	//通过Key循环获取属性
	auto iter = keys.begin();
	std::stack<YAML::Node> st;
	st.push((*node)[*iter++]);
	for (; iter != keys.end(); ++iter)
	{
		auto tmp = st.top()[*iter];
		st.pop();
		st.push(tmp);
	}
	auto curr = st.top();
	if (curr.Type() != YAML::NodeType::Scalar)
		return "";
	return curr.as<std::string>();
}

void YamlHelper::parseDbConnUrl(const std::string& url, std::string* ip, int* port, std::string* dbname)
{
	//第一次通过?拆分
	std::string data = StringUtil::split(url, "?")[0];
	//第二次通过//拆分
	auto tmp = StringUtil::split(data, "//");
	data = tmp[1];
	//设置数据库名称
	*dbname = tmp[2];
	//获取ip和端口
	tmp = StringUtil::split(data, ":");
	*ip = tmp[0];
	*port = atoi(tmp[1].c_str());
}
