#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 14:08:32

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
#ifndef _SCIRESULTMAPPER_H_
#define _SCIRESULTMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/sciresult/SciResultDO.h"

class SciResultMapper : public Mapper<SciResultDO>
{
public:
	SciResultDO mapper(ResultSet* resultSet) const override
	{
		SciResultDO data;
		data.set_UPDATEMAN(resultSet->getString(1));
		data.set_PIMRESEARCHFINDINGSNAME(resultSet->getString(2));
		data.set_FJ(resultSet->getString(3));
		data.set_ENABLE(resultSet->getString(4));
		data.set_CREATEDATE(resultSet->getString(5));
		data.set_UPDATEDATE(resultSet->getString(6));
		data.set_CREATEMAN(resultSet->getString(7));
		data.set_PIMRESEARCHFINDINGSID(resultSet->getString(8));
		data.set_PIMPERSONID(resultSet->getString(9));
		data.set_HQSJ(resultSet->getString(10));
		data.set_JLSS(resultSet->getString(11));
		data.set_JLSPZT(resultSet->getString(12));
		data.set_JLGLBH(resultSet->getString(13));
		data.set_JLCZZ(resultSet->getString(14));
		data.set_REASON(resultSet->getString(15));
		return data;
	}
};

#endif // !_CONTRACTMAPPER_H_