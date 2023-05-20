#pragma once
/*
 Copyright Zero One Star. All rights reserved.
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/dto/work-history/WorkHistoryDTO.h"
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _WORKHISTORYSERVICE_H_
#define _WORKHISTORYSERVICE_H_

#include "domain/dto/work-history/WorkHistoryFindDTO.h"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/dto/work-history/WorkHistoryDTO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"

class WorkHistoryService
{
public:
	// 分页查询所有数据
	WorkHistoryFindPageDTO::Wrapper listAll(const WorkHistoryPageQuery::Wrapper& query);








	////查询数据详情
	WorkHistoryDTO::Wrapper listDetail(const WorkHistoryQuery::Wrapper& query);

	bool updateData(const WorkHistoryDTO::Wrapper& dto);
};

#endif // !_WORKHISTORYSERVICE_H_