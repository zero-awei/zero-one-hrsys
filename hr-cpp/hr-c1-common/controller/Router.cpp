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
#include "ApiHelper.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "uselib/ws/WSController.h"
#endif
//测试
#include "certDropDownList/profCertsList/ProfCertsListController.h"
#include "certDropDownList/certTypeList/CertTypeListController.h"
#include "contractType/ContractTypeListController.h"
#include "armyLevelType/ArmyLevelTypeController.h"
#include "fileStatus/FileStatusController.h"
#include "fileReservation/FileReservationController.h"
#include "jobLevelTypeList/JobLevelTypeListController.h"
#include "costTypeList/CostTypeListController.h"

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
#endif

	//#TIP :系统扩展路由定义，写在这个后面
	createContractTypeRouter();
	createArmyLevelTypeRouter();
	createRouter();
	//本地测试
	creatTestRouter();
	createJobLevelTypeRouter();
	createCostTypeRouter();
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif

//本地测试
void Router::creatTestRouter()
{
	// 绑定职业资格证书类型下拉列表控制器
	ROUTER_SIMPLE_BIND(ProfCertsListController);
	ROUTER_SIMPLE_BIND(CertTypeListController);
}

void Router::createRouter()
{
	ROUTER_SIMPLE_BIND(FileReservationController);
	ROUTER_SIMPLE_BIND(FileStatusController);
}

void Router::createContractTypeRouter()
{
	ROUTER_SIMPLE_BIND(ContractTypeListController);
}

void Router::createArmyLevelTypeRouter()
{
	ROUTER_SIMPLE_BIND(ArmyLevelTypeController);
}

void Router::createJobLevelTypeRouter()
{
	ROUTER_SIMPLE_BIND(JobLevelTypeListController);
}

void Router::createCostTypeRouter()
{
	ROUTER_SIMPLE_BIND(CostTypeListController);
}