#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/27 16:52:03

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
#ifndef _EXPORTROCKET_H_
#define _EXPORTROCKET_H_

#include "RocketClient.h"
#include <memory>
#include "oatpp/core/Types.hpp"
#include "Macros.h"
#include "domain/query/work-history/WorkHistoryExportQuery.h"


class ExportRocket : public RocketClient::RConsumerListener
{
private:
	std::shared_ptr<RocketClient> client;
	std::shared_ptr<RocketClient::RSendCallback> cb;
	void init();
	DECLARE_INSTANCE(ExportRocket);
public:
	//TestRocket();
	~ExportRocket();
	void testRocket(const WorkHistoryExportQuery::Wrapper& query);
	std::string receiveMessage(std::string payload) override;
};

#endif // !_EXPORTROCKET_H_