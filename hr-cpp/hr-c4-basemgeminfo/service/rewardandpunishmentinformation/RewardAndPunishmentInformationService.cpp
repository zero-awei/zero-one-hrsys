#include "stdafx.h"
#include "RewardAndPunishmentInformationService.h"
#include"../../dao/rewardandpunishmentinformation/RewardAndPunishmentInformationDAO.h"
#include <SnowFlake.h>
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "CharsetConvertHepler.h"
#include "domain/do/rewardandpunishmentinformation/RewardAndPunishmentInformationDO.h"
#include "oatpp/core/Types.hpp"


RewardAndPunishmentInformationPageDTO::Wrapper RewardAndPunishmentInformationService::listAll(const RewardAndPunishmentInformationPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RewardAndPunishmentInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RewardAndPunishmentInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RewardAndPunishmentInformationDO> result = dao.selectWithPage(query);
	//将DO换成DTO
	for (RewardAndPunishmentInformationDO sub : result)
	{
		auto dto = RewardAndPunishmentInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, lx, Lx, pimrewardpunishmentname, Pimrewardpunishmentname, pimpersonid, Pimpersonid, pimrewardpunishmentid, Pimrewardpunishmentid, jcjb, Jcjb, jcje, Jcje, jlsj, Jlsj, jcsj, Jcsj, bz, Bz, fj, Fj, updateman, Updateman, createman, Createman, createdate, Createdate, updatedate, Updatedate);
		pages->addData(dto);
	}
	return pages;
}

uint64_t RewardAndPunishmentInformationService::saveData(const AddRewardAndPunishmentInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	RewardAndPunishmentInformationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Lx, lx, Pimrewardpunishmentname, pimrewardpunishmentname, Jcjb, jcjb, Jcje, jcje, Jlsj, jlsj, Jcsj, jcsj,  Pimpersonid, pimpersonid, Pimrewardpunishmentid, pimrewardpunishmentid, Updateman, updateman, Createman, createman, Createdate, createdate, Updatedate, updatedate, Bz, bz, Fj, fj);
	// 生成唯一标识
	SnowFlake sf(1, 4);
	auto id = sf.nextId();
	data.setPimrewardpunishmentid(to_string(id));
	// 设置更新时间和创建时间
	data.setUpdatedate(SimpleDateTimeFormat::format());
	data.setCreatedate(data.getUpdatedate());
	// 从负载数据中获取创建人
	data.setCreateman(payload.getUsername());
	data.setUpdateman(payload.getUsername());
	// 执行数据添加
	RewardAndPunishmentInformationDAO dao;
	if (dao.insert(data)) {
		return id;
	}
	return 0;
}

bool RewardAndPunishmentInformationService::removeData(const DelRewardAndPunishmentInformationDTO::Wrapper& dto)
{
	RewardAndPunishmentInformationDAO dao;
	std::string pimpersonid = dto->pimpersonid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}

uint64_t RewardAndPunishmentInformationService::saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload)
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

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("奖惩信息表");
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);
	RewardAndPunishmentInformationDAO dao;
	SnowFlake sf(1, 4);
	bool tem = true;
	int len = 0;
	for (auto row : readData)
	{

		//判断文件中是否有数据
		for (unsigned int j = 0; j < row.size(); ++j)
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
		RewardAndPunishmentInformationDO data(row);
		//雪花算法生产id
		data.setPimrewardpunishmentid(to_string(sf.nextId()));

		//判断是谁的科研成果
		data.setPimpersonid(pimpersonid);

		//更新时间
		//SimpleDateTimeFormat times;
		data.setUpdatedate(SimpleDateTimeFormat::format());
		data.setCreatedate(data.getUpdatedate());
		// 从负载数据中获取创建人
		data.setCreateman(payload.getUsername());
		data.setUpdateman(payload.getUsername());

		//插入数据
		len = dao.insert(data);

	}
	return uint64_t(len);
}
