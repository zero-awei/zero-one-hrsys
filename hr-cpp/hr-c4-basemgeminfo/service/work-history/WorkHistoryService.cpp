#include "stdafx.h"
#include "WorkHistoryService.h"
#include "../../dao/work-history/WorkHistoryDAO.h"

WorkHistoryDTO::Wrapper WorkHistoryService::listDetail(const WorkHistoryQuery::Wrapper& query)
{
	// 构建返回对象
	//auto lists = MilitaryDTO::createShared();
	WorkHistoryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = WorkHistoryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), rzkssj, Rzkssj,rzjssj, Rzjssj, ormorgname, Ormorgname, ormdutyname, Ormdutyname, ormpostname, Ormpostname, cfplx, Cfplx, enable,Enable);
	}
	return dto;
}

bool WorkHistoryService::updateData(const WorkHistoryDTO::Wrapper& dto)
{
	// 组装DO数据
	WorkHistoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rzkssj, rzkssj, Rzjssj, rzjssj, Ormorgname, ormorgname, Ormdutyname, ormdutyname, Ormpostname, ormpostname, Cfplx, cfplx, Enable, enable);
	// 执行数据修改
	WorkHistoryDAO dao;
	return dao.update(data) == 1;
}