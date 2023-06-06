/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:15:07
 
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
#include "TestRocket.h"
#include <iostream>
#include "domain/dto/work-history/WorkHistoryMqDTO.h"
#include "service/work-history/WorkHistoryService.h"



void TestRocket::init()
{
	this->client = nullptr;
	this->cb = nullptr;
}

//TestRocket::TestRocket()
//{
//	
//}

TestRocket::~TestRocket()
{
	if (client)
	{
		client->unsubscribe();
	}
}

void TestRocket::testRocket(const String& fileName, const String& pimpersonid, const PayloadDTO& payload)
{
	// 创建客户端
	client = make_shared<RocketClient>("8.130.122.117:9876");
	// 创建发送消息回调
	cb = make_shared<RocketClient::RSendCallback>([](SendStatus staus)
		{
			//std::cout << "RSendCallback send status: " << staus << endl;
		});
	
	// 测试开启订阅
	client->subscribe("into");
	client->addListener(this);
	//// 定义消息对象
	auto dto = WorkHistoryMqDTO::createShared();
	dto->body = fileName;
	dto->pimpersonid = pimpersonid;
	dto->creatName = payload.getUsername();
	//auto dto = SampleDTO::createShared();
	//dto->name = "cat";
	//dto->sex = "man";
	//dto->age = 10;
	//// 发送消息
	//dto->id = 1;
	//RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, null);
	//dto->id = 2;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "into", dto, NULL);
	//dto->id = 3;
	/*RC_PUBLISH_OBJ_MSG_SYNC(res1, client, "into", dto);
	std::cout << "sync send result: " << res1 << endl;*/
}

void TestRocket::receiveMessage(std::string payload)
{
	RC_RECEIVER_MSG_CONVERT(dto, WorkHistoryMqDTO, payload);
	///*std::cout << "receiveMessage: " << dto->id.getValue(-1)
	//	<< "-" << dto->name.getValue("")
	//	<< "-" << dto->sex.getValue("")
	//	<< "-" << dto->age.getValue(0)
	//	<< endl;*/
	WorkHistoryService service;
	service.saveManyData(dto->body,  dto->pimpersonid, dto->creatName);
}
