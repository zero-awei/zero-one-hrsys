#include "stdafx.h"
#include "WorkHistoryService.h"
#include "dao/work-history/WorkHistoryDAO.h"
#include "domain/do/work-history/DelWorkHistoryDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/work-history/WorkHistoryIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

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

uint64_t WorkHistoryService::saveManyData(const String& fileBody, const String& suffix, const String& pimpersonid)
{
	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/Excel/";

	// 计算时间戳
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// 获取毫秒
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// 拼接后缀名
	ss << suffix.getValue("");

	// 临时文件名称
	std::string fileName = ss.str();
	// 保存文件到临时目录
	fileBody.saveToFile(fileName.c_str());


	// 保存到文件
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("工作履历表");
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);

	WorkHistoryDAO dao;
	
	SnowFlake sf(0, 31);

	bool tem = true;
	for (auto row : readData)
	{

		//判断文件中是否有数据
		for (int j = 0; j < row.size(); ++j)
		{
			if (row[j].empty())
			{
				return -1;
			}
			std::cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}
		
		std::cout << endl;
		if (tem)
		{
			tem = false;
			continue;
		}
		AddWorkHistoryDO data(row);
		//雪花算法生产履历id
		data.setpIMWORKHISTORYID(to_string(sf.nextId()));

		//判断是谁的工作履历
		data.setpIMPERSONID(pimpersonid);

		//更新时间
		SimpleDateTimeFormat times;


		//插入数据
		dao.insert(data);

	}

	//执行添加逻辑
}
