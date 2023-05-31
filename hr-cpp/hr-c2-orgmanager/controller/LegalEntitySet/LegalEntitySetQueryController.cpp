#include "stdafx.h"
#include "LegalEntitySetQueryController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "FastDfsClient.h"
#include "tree/TreeUtil.h"
#include "service/LegalEntitySet/LegalEntitySetService.h"


/* 法人主体设置控制器具体实现--（组织管理-数据设置-法人主体设置）--TripleGold */

LegalEntitySetQueryPageJsonVO::Wrapper LegalEntitySetQueryController::execQueryLES(const LegalEntitySetQuery::Wrapper& query)
{
	// 定义一个Service
	LegalEntitySetService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LegalEntitySetQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
