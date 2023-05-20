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

#include "GoshController/TestController.h"
#include "SelectController/retirement.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "uselib/ws/WSController.h"
#endif
#include "LDConstroller/LaborDispatchConstroller.h"


#include "Muggle/labor_dispatch-Muggle.h"
#include "Muggle/expense_ledger-Muggle.h"
#include "controller/JobTitle/JobTitleController.h"
#include "GoshController/TestController.h"



#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
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
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(LaborDispatchConstroller);
	ROUTER_SIMPLE_BIND(TestController);
	ROUTER_SIMPLE_BIND(JobTitleController);
	ROUTER_SIMPLE_BIND(ExpenseLedgerMController);
	ROUTER_SIMPLE_BIND(LaborDispatchConstroller);
	ROUTER_SIMPLE_BIND(GoshController);
}
#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);

	// ��ְ�ƹ��������
	ROUTER_SIMPLE_BIND(JobTitleController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif

void Router::createRouter()
{

}