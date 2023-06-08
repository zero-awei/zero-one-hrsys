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
#include "jobSet/jobOutput/JobOutputController.h"
#include "jobSet/jobUpdate/JobUpdateController.h"
#include "jobSet/addJobController/AddJobController.h"
// 项目标签
#include "projTag/pageQueryProjTagList/PageQueryProjTagListController.h"
#include "projTag/deleteProjTag/DeleteProjTagController.h"
#include "projTag/exportProjTagController/ExportProjTagController.h"
#include "projTag/importTagController/ImportTagController.h"
#include "projTag/addTagController/AddTagController.h"
#include "projTag/modifyProjTagController/ModifyProjTagController.h"
#include "projTag/itemLabel/ItemLabelController.h"
#include "projTag/queryOrgList/QueryOrgListController.h"
//编制查询
#include "orgbz/PageQueryBzController.h"

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
	createBzRouter();
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
	 * 导入岗位&新增岗位
	 * 负责人：Andrew
	 */
	ROUTER_SIMPLE_BIND(ImportJobController);
	ROUTER_SIMPLE_BIND(AddJobController);
	/**
	 * 查询指定岗位详情&删除岗位
	 * 负责人：米饭
	 */
	ROUTER_SIMPLE_BIND(PostQueryController);
	ROUTER_SIMPLE_BIND(PostDeleteController);
	/**
	 * 更新岗位&导出岗位
	 * 负责人：狗皮电耗子
	 */
	ROUTER_SIMPLE_BIND(JobOutputController);
	ROUTER_SIMPLE_BIND(JobUpdateController);
}

void Router::createProjTagRouter()
{
	/**
	 * 导出项目标签&更新项目标签&组织列表分页查询
	 * 负责人：Andrew
	 */
	ROUTER_SIMPLE_BIND(ExportProjTagController);
	ROUTER_SIMPLE_BIND(ModifyProjTagController);
	ROUTER_SIMPLE_BIND(QueryOrgListController);
	/**
	 * 导入项目标签&新增项目标签
	 * 负责人：远翔
	 */
	ROUTER_SIMPLE_BIND(ImportTagController);
	ROUTER_SIMPLE_BIND(AddTagController);
	/**
	 * 分页查询项目标签&删除项目标签
	 * 负责人：咫尺之书
	 */
	ROUTER_SIMPLE_BIND(PageQueryProjTagListController);
	ROUTER_SIMPLE_BIND(DeleteProjTagController);
	/**
	 * 查询指定项目标签详情
	 * 负责人：缘尘
	 */
	ROUTER_SIMPLE_BIND(ItemLabelController);
}

void Router::createBzRouter()
{
	/**
	 * 编制查询
	 * 负责人：xubuxi
	 */
	ROUTER_SIMPLE_BIND(PageQueryBzController);
}
