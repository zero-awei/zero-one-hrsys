/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "Router.h"
#include "controller/GoshController/TestController.h"

#include "GoshController/TestController.h"
#include "JobTitleInfo/JobTitleInfoController.h"
#include "ExpenseLedge/ExpenseLedgeController.h"
#include "./ContractController/ContractController.h"
#include "../uselib/ws/WSController.h"
#include "./retirementController/retirement.h"
#include "./JobTitle/JobTitleController.h"
#include "./ContractManagement/Contractmanagement.h"

#ifdef HTTP_SERVER_DEMO
#include "./ContractController/ContractController.h"
#include "../uselib/ws/WSController.h"
#endif
#include "muggle/LaborDispatchController.h"
#include "muggle/ExpenseLedgerController.h"
#include "LaborDispatch/LaborDispatchConstroller.h"
#include "GoshController/TestController.h"
#include "TerminationReminder/terminationReminder.h"

// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
	createJobAndExpenseRouter();
#endif

	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(ContractController);
	ROUTER_SIMPLE_BIND(LaborDispatchMController);
	ROUTER_SIMPLE_BIND(ExpenseLedgerMController);
	ROUTER_SIMPLE_BIND(LaborDispatchConstroller);
	ROUTER_SIMPLE_BIND(RetirementController);
	ROUTER_SIMPLE_BIND(JobTitleController);
	ROUTER_SIMPLE_BIND(GoshController);
	ROUTER_SIMPLE_BIND(GoshController);
	ROUTER_SIMPLE_BIND(TerminationReminderController);
	ROUTER_SIMPLE_BIND(ContractmanageController);
}	


void Router::createJobAndExpenseRouter()
{
	ROUTER_SIMPLE_BIND(JobTitleInfoController);
	ROUTER_SIMPLE_BIND(ExpenseLedgeController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定合同控制器
	ROUTER_SIMPLE_BIND(ContractController);

	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}

#endif
