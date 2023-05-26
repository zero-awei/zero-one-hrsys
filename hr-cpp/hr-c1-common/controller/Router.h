#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:43

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
#ifndef _ROUTER_
#define _ROUTER_
#include "oatpp/web/server/api/Endpoint.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
using namespace oatpp::web::server;
using namespace oatpp::web::server::api;

/**
 * 前端访问服务器路由绑定，用于定义前端访问后端接口和访问路径绑定
 * swagger文档访问示例地址：http://localhost:8090/swagger/ui
 */
class Router
{
private:
	// 文档访问端点
	Endpoints* docEndpoints;
	// 路由对象
	HttpRouter* router;
public:
	// 构造初始化
	Router(Endpoints* docEndpoints, HttpRouter* router);
	// 呼叫初始化
	void initRouter();

private:

#ifdef HTTP_SERVER_DEMO
	// 创建演示路由
	void createSampleRouter();

#endif
	/**
	 * 绑定档案保管地和档案状态下拉列表
	 * 负责人：远翔
	 */
	void createFileReservationRouter();
	void createFileStatusRouter();
	/**
	 * 绑定证书类型和职业资格证书类型下拉列表
	 * 负责人：米饭
	 */
	void creatTestRouter();

	/**
	 * 绑定合同类型&军转级别下拉列表路由
	 * 负责人：Andrew
	 */
	void createTypeContractRouter();
	void createArmyLevelTypeRouter();
	void createContractStatusRouter();

	/**
	 * 绑定职称等级类型&费用类别下拉列表路由
	 * 负责人：咫尺之书
	 */
	void createJobLevelTypeRouter();
	void createCostTypeRouter();

	/**
	 * 档案室层级&申报类型下拉列表
	 * 负责人：狗皮电耗子
	 */
	void createDeclareRouter();
	void createArchivesLevelsRouter();

	/**
	 * 获奖等级&岗位类别下拉列表
	 * 负责人：缘尘
	 */
	void createAwardLevelRouter();
	void createJobCategoryRouter();
	
	/**
	 * 绑定离职原因&解聘原因下拉列表
	 * 负责人：远翔
	 */
	void createLeaveReasonRouter();
	void createDismissReasonRouter();
	//审阅状态下拉列表&评价类型下拉列表
	// 负责人：凤雏
	void createAuditStatusRouter();
	void createEvalutionTypesRouter();
};

#endif // !_ROUTER_
