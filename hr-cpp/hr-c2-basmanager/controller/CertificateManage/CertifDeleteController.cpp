/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "CertifDeleteController.h"
//#include "../../service/sample/SampleService.h"


Uint64JsonVO::Wrapper CertifDeleteController::execRemoveCertif(const RemoveCertifDTO::Wrapper& dto)
{
	
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	/*
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SampleService service;
	// 执行数据删除
	if (service.removeData(dto->id.getValue(0))) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	*/
	return jvo;
}