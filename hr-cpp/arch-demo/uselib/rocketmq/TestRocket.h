#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:14:36
 
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
#ifndef _TESTROCKET_H_
#define _TESTROCKET_H_
#include "RocketClient.h"
#include <memory>

/**
 * ≤‚ ‘RocketMQ
 */
class TestRocket : public RocketClient::RConsumerListener
{
private:
	std::shared_ptr<RocketClient> client;
	std::shared_ptr<RocketClient::RSendCallback> cb;
public:
	TestRocket();
	~TestRocket();
	void testRocket();
	void receiveMessage(std::string payload) override;
};
#endif // _TESTROCKET_H_
