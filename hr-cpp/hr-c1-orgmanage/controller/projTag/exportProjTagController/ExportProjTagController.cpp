/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/18 16:32:02

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
#include "ExportProjTagController.h"
#include "service/projTag/ProjTagService.h"

StringJsonVO::Wrapper ExportProjTagController::execExportProjTag(const ExportProjTagQuery::Wrapper& query)
{
	// 构建返回对象
	auto vo = StringJsonVO::createShared();

	// 参数校验
	if (query->order->empty() || (query->order != "DESC" && query->order != "ASC"))
	{
		vo->init("", RS_PARAMS_INVALID);
		return vo;
	}

	// 最大5000条
	if (query->line > 5000) 
		query->line = 5000;

	// TODO: 调用service获取导出文件下载链接
	ProjTagService service;
	string url = service.exportProjTag(query);

	if (url.empty()) 
		vo->fail(url);
	else 
		vo->success(url);
	return vo;
}
