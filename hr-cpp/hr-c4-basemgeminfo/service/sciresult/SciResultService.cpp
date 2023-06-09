#include "stdafx.h"
#include "SciResultService.h"
#include"../../dao/sciresult/SciResultDAO.h"
#include <SnowFlake.h>
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "CharsetConvertHepler.h"
#include "domain/do/sciresult/SciResultDO.h"
using namespace oatpp;
SciResultPageDTO::Wrapper SciResultService::listAll(const SciResultQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = SciResultPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	SciResultDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<SciResultDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (SciResultDO sub : result)
	{
		auto dto = SciResultDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,UPDATEMAN,_UPDATEMAN, PIMRESEARCHFINDINGSNAME, _PIMRESEARCHFINDINGSNAME, FJ, _FJ,ENABLE,_ENABLE, CREATEDATE,_CREATEDATE,CREATEMAN,_CREATEMAN,UPDATEDATE,_UPDATEDATE,CREATEMAN,_CREATEMAN, PIMRESEARCHFINDINGSID, _PIMRESEARCHFINDINGSID, PIMPERSONID, _PIMPERSONID, HQSJ, _HQSJ,JLSS,_JLSS, JLSPZT,_JLSPZT, JLGLBH,_JLGLBH, JLCZZ,_JLCZZ, REASON,_REASON);
		pages->addData(dto);

	}
	return pages;
}
uint64_t SciResultService::saveData(const Add2SciResultDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	SciResultDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _PIMRESEARCHFINDINGSNAME, PIMRESEARCHFINDINGSNAME, _HQSJ, HQSJ, _FJ, FJ, _PIMPERSONID, PIMPERSONID);
	// 生成唯一标识
	SnowFlake sf(1, 4);
	auto id = sf.nextId();
	data.set_PIMRESEARCHFINDINGSID(to_string(id));
	// 设置更新时间和创建时间
	data.set_UPDATEDATE(SimpleDateTimeFormat::format());
	data.set_CREATEDATE(data.get_UPDATEDATE());
	// 从负载数据中获取创建人
	data.set_CREATEMAN(payload.getUsername());
	data.set_UPDATEMAN(payload.getUsername());
	// 执行数据添加
	SciResultDAO dao;
	if (dao.insert(data)) {
		return id;
	}
	return 0;
}
bool SciResultService::removeData(const DelSciResultDTO::Wrapper& dto)
{
	/*// 组装DO数据
	DelWorkHistoryDO data;


	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMPERSONID, pimpersonid);*/

	SciResultDAO dao;
	std::string pimpersonid = dto->PIMPERSONID;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}
uint64_t SciResultService::saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload)
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

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("科研成果表");
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);

	SciResultDAO dao;

	SnowFlake sf(1, 4);

	bool tem = true;
	for (auto row : readData)
	{

		//判断文件中是否有数据
		for (size_t j = 0; j < row.size(); ++j)
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
		SciResultDO data(row);
		//雪花算法生产id
		data.set_PIMRESEARCHFINDINGSID(to_string(sf.nextId()));

		//判断是谁的科研成果
		data.set_PIMPERSONID(pimpersonid);

		//更新时间
		data.set_UPDATEDATE(SimpleDateTimeFormat::format());
		data.set_CREATEDATE(data.get_UPDATEDATE());
		// 从负载数据中获取创建人
		data.set_CREATEMAN(payload.getUsername());
		data.set_UPDATEMAN(payload.getUsername());

		//插入数据
		dao.insert(data);

	}

	return uint64_t(1);
	//执行添加逻辑
}
