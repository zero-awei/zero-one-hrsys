#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/23 18:08:32

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
#ifndef _CERTTYPE_DO_
#define _CERTTYPE_DO_
#include "../DoInclude.h"

/**
 * 证书类型下拉列表查询DO
 * 负责人：米饭
 */
class CertTypeDO
{
	// 证书类型ID
	CC_SYNTHESIZE(string, certTypeId, CertTypeId);
	// 证书类型名称
	CC_SYNTHESIZE(string, certTypeName, CertTypeName);
	// 证书类型代号
	CC_SYNTHESIZE(string, certTypeCode, CertTypeCode);
	// 证书类型是否有效 (0无效, 1有效)
	CC_SYNTHESIZE(bool, certTypeValidity, CertTypeValidity);

public:
	CertTypeDO() {
		certTypeId = "";
		certTypeName = "";
		certTypeCode = "";
		certTypeValidity = 1;
	}
};

#endif // !_CERTTYPE_DO_
