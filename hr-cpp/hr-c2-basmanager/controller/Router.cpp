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
#include "RosterOfPer/FormerEmployeesController.h"
#include "CertificateManage/UpdateCertificateController.h"
//pine
#include "controller/CertificateManage/CheckCerListController.h"
#include "controller/CertificateManage/CreateNewCerController.h"
#include "controller/RosterOfPer/CheckRetiresListController.h"
#include "controller/RosterOfPer/ExportRetireesController.h"

#include "RosterOfPer/EmployeePageController.h"
#include "CertificateManage/CertifDeleteController.h"
#include "CertificateManage/ExportCertifController.h"
#include "RosterOfPer/ExportEmployeeController.h"
#include "controller/RosterOfPer/RraineeController.h"

//测试controller引入头文件
#include "controller/RosterOfPer/TemporaryStaffController.h"
#include "controller/CertificateManage/EmployeeInfoController.h"
#include "controller/CertificateManage/CertificateTypeController.h"

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
	ROUTER_SIMPLE_BIND(CheckCerListController);//分页查询证书列表--(证书管理-分页查询证书列表)--pine
	ROUTER_SIMPLE_BIND(CreateNewCerController);//新建证书--(证书管理-新建证书)--pine
	ROUTER_SIMPLE_BIND(CheckRetiresListController);//人员花名册-（离退休员工-分页查询员工列表）--pine
	ROUTER_SIMPLE_BIND(ExportRetireesController); //人员花名册 - （离退休员工 - 导出员工）--pine
	ROUTER_SIMPLE_BIND(FormerEmployeesController);
	ROUTER_SIMPLE_BIND(UpdateCertificateController);	
	ROUTER_SIMPLE_BIND(RraineeController);  // 见习员工 swagger效果测试
	ROUTER_SIMPLE_BIND(TempStaffController);//挂职人员swagger效果测试
	ROUTER_SIMPLE_BIND(EmployeeInfoController);//人员信息查询swagger效果测试
	ROUTER_SIMPLE_BIND(CertificateTypeController); //证书类型查询swagger效果测试
	ROUTER_SIMPLE_BIND(CheckCerListController);
	ROUTER_SIMPLE_BIND(CreateNewCerController);
	ROUTER_SIMPLE_BIND(CheckRetiresListController);
	ROUTER_SIMPLE_BIND(ExportRetireesController);
	ROUTER_SIMPLE_BIND(EmployeePageController); //（人员花名册 - 人员花名册 - 分页查询员工数据）--洛洛
	ROUTER_SIMPLE_BIND(CertifDeleteController); //（证书管理 - 证书信息 - 删除证书）--洛洛
	ROUTER_SIMPLE_BIND(ExportCertifController); //（证书管理 - 证书信息 - 导出证书）--洛洛
	ROUTER_SIMPLE_BIND(ExportEmployeeController);//（人员花名册 - 人员花名册 - 导出员工（导出本页在前端完成））--洛洛
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

