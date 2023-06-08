#include "stdafx.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "ProbationaryEmployeeService.h"
#include "../../dao/RosterOfPer/ProbationaryEmployeeDAO.h"
#include "FastDfsClient.h"

ProbationaryEmployeePageDTO::Wrapper ProbationaryEmployeeService::listAll(const ProbationaryEmployeeQuery::Wrapper& query)
{
	auto pages = ProbationaryEmployeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ProbationaryEmployeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}


	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProbationaryEmployeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ProbationaryEmployeeDO sub : result)
	{
		auto dto = ProbationaryEmployeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PIMPERSONID, pimPersonId,id, YGBH, name, PIMPERSONNAME,
			zz, ORMORGNAME, bm, ORMORGSECTORNAME,
			zw, ZW, gw, ORMPOSTNAME, rzsj, RZSJ,
			daoqishijian, SYDQ);
		pages->addData(dto);
	}

	return pages;
}

std::string ProbationaryEmployeeService::exportData(const ProbationaryEmployeeQuery::Wrapper& query)
{
	ProbationaryEmployeeDAO dao;
	auto listdata = dao.selectAll(query);

	std::vector<std::vector<std::string>> datas;

	std::vector<std::string> rowHead;
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("员工编号"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("姓名"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("组织"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("部门"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("职务"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("岗位"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("任职时间"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("试用到期时间"));

	datas.push_back(rowHead);

	for (auto row : listdata)
	{
		std::vector<std::string> vec = row.ProbationaryEmployeetoVector();
		datas.push_back(vec);
	}

	std::stringstream ss;
	ss << "public/static/Excel/";


	// 计算时间戳
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// 获取毫秒
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tSeconds - tMilli;
	ss << setfill('0') << setw(3) << ms.count();
	// 拼接后缀
	ss << ".xlsx";

	std::string fileName = CharsetConvertHepler::ansiToUtf8(ss.str());
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("试用员工信息表");

	// 保存到Excel
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);


	// 上传到FastDFS文件服务器
#ifdef LINUX
//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15:8888/" << fieldName;

	cout << ss.str() << endl;

	// 删除本地文件
	const char* filename = fileName.c_str();
	if (std::remove(filename) != 0) {
		// 删除失败
		std::perror("Error deleting local file");
	}
	else {
		// 删除成功
		std::puts("Local file successfully deleted");
	}

	return ss.str();
}
