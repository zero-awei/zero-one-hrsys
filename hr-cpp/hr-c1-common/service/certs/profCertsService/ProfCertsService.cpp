/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 14:30:11

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
#include "../../../dao/certs/profCertsDAO/ProfCertsDAO.h"
#include "ProfCertsService.h"

ProfCertsListDTO::Wrapper ProfCertsService::listAll(const ProfCertsQuery::Wrapper& query)
{
	// 构建返回对象
	auto profCertsListDTO = ProfCertsListDTO::createShared();
	profCertsListDTO->pageIndex = query->pageIndex;
	profCertsListDTO->pageSize = query->pageSize;

	// 查询数据总条数
	ProfCertsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return profCertsListDTO;
	}

	// 分页查询数据
	profCertsListDTO->total = count;
	profCertsListDTO->calcPages();
	list<ProfCertsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ProfCertsDO profCertsDO : result)
	{
		auto profCertsDTO = ProfCertsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(profCertsDTO, profCertsDO, pimQualMajorId, PimQualMajorId, pimQualMajorName, PimQualMajorName, createMan, CreateMan, createDate, CreateDate
			, enable, Enable, upDateMan, UpDateMan, upDateDate, UpDateDate, pimQualTypeId, PimQualTypeId
			, ormOrgId, OrmOrgId, professionalType, ProfessionalType, zyjszw, Zyjszw, quaLevel, QuaLevel
			, quaMajor, QuaMajor, gwlx, Gwlx, gwType, GwType, gwzs, Gwzs, pimQualTypeName, PimQualTypeName)
		profCertsListDTO->addData(profCertsDTO);

	}
	return profCertsListDTO;
}
