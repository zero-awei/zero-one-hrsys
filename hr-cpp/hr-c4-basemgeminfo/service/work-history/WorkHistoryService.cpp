#include "stdafx.h"
#include "WorkHistoryService.h"
#include "dao/work-history/WorkHistoryDAO.h"
#include "domain/do/work-history/DelWorkHistoryDO.h"

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


WorkHistoryFindPageDTO::Wrapper WorkHistoryService::listAll(const WorkHistoryPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = WorkHistoryFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	WorkHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<WorkHistoryFindDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (WorkHistoryFindDO sub : result)
	{
		auto dto = WorkHistoryFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rzkssj, rZKSSJ, rzjssj, rZJSSJ, \
			ormorgname, oRMORGNAME, ormorgsectorname, oRMORGSECTORNAME, \
			ormdutyname, oRMDUTYNAME, ormpostname, oRMPOSTNAME, cfplx, cFPLX, \
			experience, eXPERIENCE, pimworkhistoryid, pIMWORKHISTORYID, pimpersonid, pIMPERSONID);
		pages->addData(dto);

	}
	return pages;
}

uint64_t WorkHistoryService::saveData(const AddWorkHistoryDTO::Wrapper& dto)
{
	// 组装DO数据
	AddWorkHistoryDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, rZKSSJ, rzkssj, \
		rZJSSJ, rzjssj, oRMORGNAME, ormorgname, oRMORGSECTORNAME,\
		ormorgsectorname, oRMDUTYNAME, ormdutyname, oRMPOSTNAME, \
		ormpostname, cFPLX, cfplx, eXPERIENCE, experience, \
		pIMWORKHISTORYID, pimworkhistoryid, pIMPERSONID, pimpersonid)
		// 执行数据添加
		WorkHistoryDAO dao;
	return dao.insert(data);
}

bool WorkHistoryService::removeData(const DelWorkHistoryDTO::Wrapper& dto)
{
	/*// 组装DO数据
	DelWorkHistoryDO data;


	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMPERSONID, pimpersonid);*/

	WorkHistoryDAO dao;
	std::string pimpersonid = dto->pimpersonid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}
