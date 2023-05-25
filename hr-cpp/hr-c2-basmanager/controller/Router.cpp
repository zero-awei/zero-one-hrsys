
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "controller/CertificateManage/CheckCerListController.h"
#include "controller/CertificateManage/CreateNewCerController.h"
#include "controller/RosterOfPer/CheckRetiresListController.h"
#include "controller/RosterOfPer/ExportRetireesController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
//#include "sample/SampleController.h"
#include "uselib/ws/WSController.h"
#endif

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
