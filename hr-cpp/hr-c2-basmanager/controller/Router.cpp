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
//pine
#include "controller/CertificateManage/CheckCerListController.h"
#include "controller/CertificateManage/CreateNewCerController.h"
#include "controller/RosterOfPer/CheckRetiresListController.h"
#include "controller/RosterOfPer/ExportRetireesController.h"
//chumengxian
#include "RosterOfPer/ProbationaryEmployeeController.h"
#include "RosterOfPer/FormerEmployeesController.h"
#include "CertificateManage/UpdateCertificateController.h"
//luoluo
#include "RosterOfPer/EmployeePageController.h" 
#include "CertificateManage/CertifDeleteController.h" 
#include "CertificateManage/ExportCertifController.h" 
#include "RosterOfPer/ExportEmployeeController.h"
#include "controller/RosterOfPer/LoanedPerPageController.h"
//Cpt
#include "controller/RosterOfPer/RraineeController.h"
//weixiaoman
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
	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(CheckCerListController);//分页查询证书列表--(证书管理-分页查询证书列表)--pine
	ROUTER_SIMPLE_BIND(CreateNewCerController);//新建证书--(证书管理-新建证书)--pine
	ROUTER_SIMPLE_BIND(CheckRetiresListController);//人员花名册-（离退休员工-分页查询员工列表）--pine
	ROUTER_SIMPLE_BIND(ExportRetireesController); //人员花名册-（离退休员工-导出员工）--pine

	ROUTER_SIMPLE_BIND(FormerEmployeesController);//基础管理 - （人员花名册 - 离职员工)-- 楚孟献
	ROUTER_SIMPLE_BIND(UpdateCertificateController);//证书管理 - (证书信息 - 查询、更新指定证书) -- 楚孟献
	ROUTER_SIMPLE_BIND(ProbationaryEmployeeController);//(基础管理 - 人员花名册 - 试用员工)-- 楚孟献

	ROUTER_SIMPLE_BIND(RraineeController);  // 基础管理 - (人员花名册 - 见习员工)  -- Cpt

	ROUTER_SIMPLE_BIND(TempStaffController);//(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
	ROUTER_SIMPLE_BIND(EmployeeInfoController);//(证书管理-分页查询员工列表)--weixiaoman
	ROUTER_SIMPLE_BIND(CertificateTypeController); //(证书管理-分页查询证书类型列表)--weixiaoman

	ROUTER_SIMPLE_BIND(EmployeePageController); //（人员花名册-人员花名册-分页查询员工数据）--洛洛
	ROUTER_SIMPLE_BIND(CertifDeleteController); //（证书管理-证书信息-删除证书）--洛洛
	ROUTER_SIMPLE_BIND(ExportCertifController); //（证书管理-证书信息-导出证书）--洛洛
	ROUTER_SIMPLE_BIND(ExportEmployeeController);//（人员花名册-人员花名册-导出员工（导出本页在前端完成））--洛洛
	ROUTER_SIMPLE_BIND(LoanedPerPageController);//（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
	
}


