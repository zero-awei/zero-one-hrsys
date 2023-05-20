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

// 岗位设置
#include "jobSet/importJobController/ImportJobController.h"
#include "jobSet/postQueryController/PostQueryController.h"
#include "jobSet/postDeleteController/PostDeleteController.h"
// 项目标签
#include "projTag/exportProjTagController/ExportProjTagController.h"
#include "projTag/importTagController/ImportTagController.h"
#include "projTag/addTagController/AddTagController.h"
#include "projTag/modifyProjTagController/ModifyProjTagController.h"

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
	createJobSetRouter();
	createProjTagRouter();
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

void Router::createJobSetRouter()
{
	/**
	 * 导入岗位
	 * 负责人：Andrew
	 */
	ROUTER_SIMPLE_BIND(ImportJobController);
	/**
	 * 查询指定岗位详情&删除岗位
	 * 负责人：米饭
	 */
	ROUTER_SIMPLE_BIND(PostQueryController);
	ROUTER_SIMPLE_BIND(PostDeleteController);
}

void Router::createProjTagRouter()
{
	/**
	 * 导出项目标签&更新项目标签
	 * 负责人：Andrew
	 */
	ROUTER_SIMPLE_BIND(ExportProjTagController);
	ROUTER_SIMPLE_BIND(ModifyProjTagController);
	/**
	 * 导入项目标签&新增项目标签
	 * 负责人：远翔
	 */
	ROUTER_SIMPLE_BIND(ImportTagController);
	ROUTER_SIMPLE_BIND(AddTagController);
}