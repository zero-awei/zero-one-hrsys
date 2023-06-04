#pragma once
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
};

#endif // !_ROUTER_