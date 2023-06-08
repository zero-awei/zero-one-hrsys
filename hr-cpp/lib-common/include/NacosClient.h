#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:06:20
 
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
#ifndef _NACOSCLIENT_H_
#define _NACOSCLIENT_H_

#include <string>
using namespace std;

#ifdef LINUX
#include "nacos/Nacos.h"
using namespace nacos;
#endif
#include "yaml-cpp/yaml.h"

/**
 * 定义一个Nacos客户端，用于封装Nacos常用操作
 * 注意：Nacos目前不支持Windows版本，
 * 所以在Windows下面使用Nacos配置其实就是读取本地配置文件，并且不支持Windows服务注册功能
 */
class NacosClient
{
private:
	//服务器地址
	string m_address;
	//命名空间
	string m_namespace;

#ifdef LINUX
	//当前命名服务
	NamingService* namingSvc;
	//注册实例ID
	std::string instanceId;
#endif
public:
	//************************************
	// Method:    NacosClient
	// FullName:  NacosClient::NacosClient
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: const string& address 服务器地址，如：39.99.114.126:8848
	// Parameter: const string& namespaceId 命名空间，如：1653f775-4782-46ad-9cd2-b60155a574c6
	//************************************
	NacosClient(const string& address, const string& namespaceId);
	
	// 析构释放资源
	~NacosClient();

	//************************************
	// Method:    getConfig
	// FullName:  NacosClient::getConfig
	// Access:    public 
	// Returns:   std::string
	// Qualifier: 获取yaml配置
	// Parameter: const string& dataId 配置ID
	// Parameter: const string& groupName 分组名称，默认值：DEFAULT_GROUP
	//************************************
	YAML::Node getConfig(const string& dataId, const string& groupName = "DEFAULT_GROUP");

	//************************************
	// Method:    getConfigText
	// FullName:  NacosClient::getConfigText
	// Access:    public 
	// Returns:   std::string
	// Qualifier: 获取文本配置
	// Parameter: const string & dataId 配置ID
	// Parameter: const string & groupName 分组名称，默认值：DEFAULT_GROUP
	//************************************
	std::string getConfigText(const string& dataId, const string& groupName = "DEFAULT_GROUP");

	//************************************
	// Method:    registerInstance
	// FullName:  NacosClient::registerInstance
	// Access:    public 
	// Returns:   bool 注册成功返回true
	// Qualifier: 注册服务
	// Parameter: const string & ip 注册服务IP地址
	// Parameter: int port 注册服务端口
	// Parameter: const string & serviceName 注册服务名称
	// Parameter: const string & groupName 分组名称，默认值：DEFAULT_GROUP
	// Parameter: const string & clusterName 集群名称，默认值：DEFAULT
	//************************************
	bool registerInstance(const string& ip, int port, const string& serviceName, const string& groupName = "DEFAULT_GROUP", const string& clusterName = "DEFAULT");
	
	//************************************
	// Method:    deregisterInstance
	// FullName:  NacosClient::deregisterInstance
	// Access:    public 
	// Returns:   bool 反注册成功返回true
	// Qualifier: 反注册服务
	// Parameter: const string & ip 注册服务IP地址
	// Parameter: int port 注册服务端口
	// Parameter: const string & serviceName 注册服务名称
	// Parameter: const string & groupName 分组名称，默认值：DEFAULT_GROUP
	// Parameter: const string & clusterName 集群名称，默认值：DEFAULT
	//************************************
	bool deregisterInstance(const string& ip, int port, const string& serviceName, const string& groupName = "DEFAULT_GROUP", const string& clusterName = "DEFAULT");
};
#endif // _NACOSCLIENT_H_
