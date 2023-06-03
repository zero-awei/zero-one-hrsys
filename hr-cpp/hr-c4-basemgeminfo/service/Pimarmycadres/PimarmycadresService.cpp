
#include "stdafx.h"
#include "PimarmycadresService.h"
#include "dao/pimarmycadres/PimarmycadresDAO.h"
#include "domain/do/pimarmycadres/DelPimarmycadresDO.h"
#include "domain/do/pimarmycadres/AddPimarmycadresDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/pimarmycadres/PimarmycadresIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "FastDfsClient.h"

uint64_t PimarmycadresService::saveManyData(const oatpp::String& fileBody, const oatpp::String& suffix, const oatpp::String& pimpersonid)
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

	PimarmycadresDAO dao;

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
		AddPimarmycadresDO data(row);
		//记录id
		data.setpIMARMYCADRESID(to_string(sf.nextId()));

		//人员id
		data.setpIMID(pimpersonid);

		//更新时间
		SimpleDateTimeFormat times;

		//插入数据
		dao.insert(data);

	}
	return uint64_t(1);
	//执行添加逻辑
}

PimarmycadresDTO::Wrapper PimarmycadresService::listDetail(const PimarmycadresQuery::Wrapper& query)
{
	// 构建返回对象
	//auto lists = MilitaryDTO::createShared();
	PimarmycadresDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = PimarmycadresDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), pimid, pIMID, 
			form, fORM, 
			level, lEVEL, 
			occurtime, oCCURTIME, 
			annexPath, aNNEXPATH);
	}
	return dto;
}

bool PimarmycadresService::updateData(const PimarmycadresDTO::Wrapper& dto)
{
	// 组装DO数据
	PimarmycadresDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Pimid,pimid);
	// 执行数据修改
	PimarmycadresDAO dao;
	return dao.update(data) == 1;
}


PimarmycadresFindPageDTO::Wrapper PimarmycadresService::listAll(const PimarmycadresPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PimarmycadresFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PimarmycadresDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PimarmycadresFindDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PimarmycadresFindDO sub : result)
	{
		auto dto = PimarmycadresFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimid, pIMID,
			form, fORM,
			level, lEVEL,
			occurtime,oCCURTIME,
			annexPath, aNNEXPATH);

		pages->addData(dto);

	}
	return pages;
}

uint64_t PimarmycadresService::saveData(const AddPimarmycadresDTO::Wrapper& dto)
{
	// 组装DO数据
	AddPimarmycadresDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMID,pimid,
		fORM,form,
		lEVEL,level,
		oCCURTIME,occurtime,
		aNNEXPATH,annexPath,
		pIMARMYCADRESID,pimarmycadresid)
		// 执行数据添加
		PimarmycadresDAO dao;
	return dao.insert(data);
}

bool PimarmycadresService::removeData(const DelPimarmycadresDTO::Wrapper& dto)
{
	PimarmycadresDAO dao;
	std::string pimpersonid = dto->pimid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}


