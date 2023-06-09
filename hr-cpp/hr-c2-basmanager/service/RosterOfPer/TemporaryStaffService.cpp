#include "stdafx.h"
#include "TemporaryStaffService.h"
#include "../../dao/RosterOfPer/TemporaryStaffDAO.h"

#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include <cstdio>
#include "FastDfsClient.h"

#ifdef LINUX
#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif
/**
* 挂职人员service--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
*/
TemporaryStaffPageDTO::Wrapper TemporaryStaffService::listAll(const TempStaffQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TemporaryStaffPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TemporaryStaffDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TemporaryStaffDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TemporaryStaffDO sub : result)
	{
		auto dto = TemporaryStaffDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, ygbh, name, pimPersonName, empStatus,
			ygzt,tempStatus, gzzt, tempOrg, gzzz,
			tempDept, gzbm, tempStartTime, gzkssj,tempEndTime, gzjssj, pimpersonId, pimpersonId);
		pages->addData(dto);
	}
	return pages;
}

std::string TemporaryStaffService::exportData(const TempStaffQuery::Wrapper& query)
{
	//查询数据并设置page的大小等
	TemporaryStaffDAO dao;
	auto count = dao.count(query);
	//if (count > 5000) query->pageSize = 5000;
	//else query->pageSize = count ;
	//query->pageIndex = 1;
	list<TemporaryStaffDO> result = dao.selectExportDatas(query);

	//构建excel数据
	std::vector<std::vector<std::string>> datas;
	//构建excel表头
	std::vector<std::string> head_datas;
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("员工编号"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("员工姓名"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("员工状态"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("挂职状态"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("挂职组织"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("挂职部门"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("挂职开始时间"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("挂职结束时间"));
	datas.push_back(head_datas);

	//填充数据
	for (auto data : result) {
		std::vector<std::string> row;
		row.push_back(data.getygbh());
		row.push_back(data.getpimPersonName());
		row.push_back(data.getygzt());
		row.push_back(data.getgzzt());
		row.push_back(data.getgzzz());
		row.push_back(data.getgzbm());
		row.push_back(data.getgzkssj());
		row.push_back(data.getgzjssj());
		datas.push_back(row);
	}

	//构建文件名和页签名称
	std::string fileName = "./TempStaffExport.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("挂职员工表");
	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);

	// 下载链接前缀
	std::string urlPrefix;
#ifdef LINUX
	// 定义一个Nacos客户端对象，用于获取配置
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// 设置url前缀
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// 从Nacos配置中心获取FastDFS客户端配置数据
	std::string config = ns.getConfigText("client.conf");
	// 定义客户端对象
	FastDfsClient client(config, false);
#else
	// 设置url前缀
	urlPrefix = "http://8.130.87.15:8888/";
	// 定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	// 上传文件
	std::string fieldName = client.uploadFile(fileName);
	//删除本地文件
	remove(fileName.c_str());
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	//std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}
