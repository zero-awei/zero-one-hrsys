#pragma once
/**
 * Copyright Zero One Star. All rights reserved.
 *
 * @Author: awei
 * @Date: 2023/06/09 11:17:08
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _ARCHIVEMAPPER_H_
#define _ARCHIVEMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/archive/ArchiveDo.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ArchiveMapper : public Mapper<ArchiveDO>
{
public:
	ArchiveDO mapper(ResultSet* resultSet) const override
	{
		ArchiveDO data;
		data.setsortID(resultSet->getUInt64(1));
		data.setarchiveName(resultSet->getString(2));
		data.setcabinetNum(resultSet->getInt(3));
		data.setlayerNum(resultSet->getInt(4));
		data.setnumID(resultSet->getInt(4));
		return data;
	}
};

#endif // _ARCHIVEMAPPER_H_
