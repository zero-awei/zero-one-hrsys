/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 14:13:11

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
#include "../../../dao/certs/certTypeDAO/CertTypeDAO.h"
#include "CertTypeService.h"

CertTypeListDTO::Wrapper CertTypeService::listAll()
{
	// 构建返回对象
	auto certTypeListDTO = CertTypeListDTO::createShared();
	CertTypeDAO certTypeDAO;

	list<CertTypeDO> result = certTypeDAO.selectAll();
	// 将DO转换成DTO
	for (CertTypeDO certTypeDO : result)
	{
		auto certTypeDTO = CertTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(certTypeDTO, certTypeDO, certTypeId, CertTypeId, certTypeName, CertTypeName, certTypeCode, CertTypeCode, certTypeValidity, CertTypeValidity)
		certTypeListDTO->addData(certTypeDTO);
	}
	return certTypeListDTO;
}
