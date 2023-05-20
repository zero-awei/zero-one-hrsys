#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:01:31
 
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
#ifndef _SEVERCONFIGINFO_H_
#define _SEVERCONFIGINFO_H_
#include "Macros.h"
#include <string>
/**
 * ��������Ϣʵ�壬���ڼ�¼��ǰ���������ӷ�������������Ϣ
 */
class ServerInfo
{
private:
	// ��Ա��ʼ��
	void init() {
		this->dbPort = 3306;
		this->dbMax = 25;
		// �������Ĵʵ�
		zhDictNode = YAML::LoadFile("zh-dict.yaml");
	}
	// ���嵥��
	DECLARE_INSTANCE(ServerInfo);
	// �������˿�
	CC_SYNTHESIZE(std::string, serverPort, ServerPort);
	// Nacos���ò���
	CC_SYNTHESIZE(std::string, nacosAddr, NacosAddr);
	CC_SYNTHESIZE(std::string, nacosNs, NacosNs);
	CC_SYNTHESIZE(std::string, regIp, RegIp);
	CC_SYNTHESIZE(std::string, serviceName, ServiceName);
	// ���ݿ�������Ϣ
	CC_SYNTHESIZE(std::string, dbUsername, DbUsername);
	CC_SYNTHESIZE(std::string, dbPassword, DbPassword);
	CC_SYNTHESIZE(std::string, dbName, DbName);
	CC_SYNTHESIZE(std::string, dbHost, DbHost);
	CC_SYNTHESIZE(int, dbPort, DbPort);
	CC_SYNTHESIZE(int, dbMax, DbMax);
	// ����һ�������ֵ仺��
	CC_SYNTHESIZE_CR_GET(YAML::Node, zhDictNode, ZhDictNode);
};
#endif // _SEVERCONFIGINFO_H_