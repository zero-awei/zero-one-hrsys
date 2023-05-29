#pragma once
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _SPERCIFIC_CERTIFICATE_DAO_
#define _SPERCIFIC_CERTIFICATE_DAO_
#include "BaseDAO.h"
#include "SpercificCertificateMapper.h"
#include "../../domain/do/CertificateManage/SpercificCertificateDO.h"
#include "../../domain/query/CertificateManage/SpercificCertificateQuery.h"

/**
 * 示例表数据库操作实现
 */
class SpercificCertificateDAO : public BaseDAO
{
public:
	// 查询数据
	std::list<SpercificCertificateDO> querySpercificC(const SpercificCertificateQuery::Wrapper& query);
	// 修改数据
	int update(const SpercificCertificateDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_SpercificCertificate_DAO_
#pragma once
