#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/28 16:21:27

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
#ifndef _USEFASTDFS_H_
#define _USEFASTDFS_H_

#include <string>
#include <sstream>

class UseFastDfs
{
	std::string host; // FastDFS服务器IP
	std::string url_prefix;
public:
	// 构造函数
	UseFastDfs(std::string host_ = "") 
		: host(host_)
	{
		std::stringstream ss;
		ss << "http://" << host << ":8888/";
		url_prefix = ss.str();
	}

	// 上传到FastDFS服务器, 返回FastDFS服务器文件保存路径
	std::string upload(std::string fileName);
	// Nacos 上传
	std::string uploadWithNacos(std::string fileName);
};

#endif // !_USEFASTDFS_H_