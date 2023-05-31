#include "stdafx.h"
#include "LoanedPerPageService.h"
#include "../../dao/RosterOfPer/LoanedPerDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include <cstdio>
/*
（人员花名册-借调人员功能)--luoluo
*/
LoanedPerPageDTO::Wrapper LoanedPerPageService::listAll(const LoanedPerPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LoanedPerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LoanedPerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<SecondedPersonnelDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (SecondedPersonnelDO sub : result)
	{
		auto dto = LoanedPerDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PIMDISTIRBUTIONID, PIMDISTIRBUTIONID, idAndName, idAndName, ygbh, ygbh, pimPersonName, pimPersonName, zz, zz, bm, bm, yzw, yzw,
			ygw, ygw, ormName, ormName, ormOrgSectorName, ormOrgSectorName, ormDutyName, ormDutyName, ormPostName, ormPostName,
			pcmydjdmxId, pcmydjdmxId, jdksrq, jdksrq, jdjsrq, jdjsrq);
		pages->addData(dto);
	}
	return pages;
}

std::string LoanedPerPageService::exportData(const LoanedPerPageQuery::Wrapper& query)
{
	//查询数据并设置page的大小等
	LoanedPerDAO dao;
	uint64_t count = dao.count(query);
	if (count > 5000) query->pageSize = 5000;
	else query->pageSize = count;
	query->pageIndex = 1;
	list<SecondedPersonnelDO> result = dao.selectWithPage(query);

	//构建excel数据
	std::vector<std::vector<std::string>> datas;
	//构建excel表头
	std::vector<std::string> head_datas;
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("员工编号"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("员工姓名"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("原组织"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("原部门"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("原职务"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("原岗位"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("新组织"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("新部门"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("新职务"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("新岗位"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("借调状态"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("借调开始时间"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("借调结束时间"));
	datas.push_back(head_datas);

	//填充数据
	for (auto data : result) {
		std::vector<std::string> row;
		row.push_back(data.getygbh());
		row.push_back(data.getpimPersonName());
		row.push_back(data.getzz());
		row.push_back(data.getbm());
		row.push_back(data.getyzw());
		row.push_back(data.getygw());
		row.push_back(data.getormName());
		row.push_back(data.getormOrgSectorName());
		row.push_back(data.getormDutyName());
		row.push_back(data.getormPostName());
		row.push_back(data.getpcmydjdmxId());
		row.push_back(data.getjdksrq());
		row.push_back(data.getjdjsrq());
		datas.push_back(row);
	}

	//构建文件名和页签名称
	std::string fileName = "./LoanedPerExport.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("借调员工表");
	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);

	// 上传FastDFS文件服务器
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	//上传文件
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	remove(fileName.c_str());
	std::stringstream ss;
	ss << "http://8.130.87.15:8888/" << fieldName;
	return ss.str();
}
