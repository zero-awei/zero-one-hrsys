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
#include "domain/dto/work-history/AddWorkHistoryDTO.h"
#include "domain/dto/work-history/DelWorkHistoryDTO.h"
#include "controller/work-history/WorkHistoryController.h"

class WorkHistoryService
{
public:
	// 分页查询所有数据
	WorkHistoryFindPageDTO::Wrapper listAll(const WorkHistoryPageQuery::Wrapper& query);


	// 增加一条数据
	uint64_t saveData(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload);


	//删除数据(支持批量删除)
	bool removeData(const DelWorkHistoryDTO::Wrapper& dto);


	//执行导入（即批量增加数据）
	uint64_t saveManyData(const std::string fileName, const String& pimpersonid, const String& createName);

	//执行导出（即把数据放入Excel表中，返回fastdfs链接）
	std::string exportData(const WorkHistoryExportQuery::Wrapper& query);






	////查询数据详情
	WorkHistoryDTO::Wrapper listDetail(const WorkHistoryQuery::Wrapper& query);

	bool updateData(const ModWorkHistoryDTO::Wrapper& dto);
};

#endif // !_WORKHISTORYSERVICE_H_