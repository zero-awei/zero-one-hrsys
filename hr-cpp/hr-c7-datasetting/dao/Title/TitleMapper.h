#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/27 11:00:03

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
#ifndef _TITLE_MAPPER_
#define _TITLE_MAPPER_
#include "Mapper.h"
#include "../../domain/do/Title/TitleDO.h"

/**
 * Ö°³ÆÄ¿Â¼±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class TitleMapper:public Mapper<TitleDO>
{
public:
	TitleDO mapper(ResultSet* resultSet)const override
	{
		TitleDO data;
		data.setId(resultSet->getUInt(1));
		data.setNum(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setDtype(resultSet->getString(4));
		data.setTTtype(resultSet->getString(5));
		return data;
	}
	
};

#endif // !_TITLEMAPPER_H_