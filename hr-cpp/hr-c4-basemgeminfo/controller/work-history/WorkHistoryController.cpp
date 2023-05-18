#include "stdafx.h"
#include "WorkHistoryController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "service/work-history/WorkHistoryService.h"


WorkHistoryFindVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryPageQuery::Wrapper& query)
{
	auto vo = WorkHistoryFindVO::createShared();

	auto pdto = WorkHistoryFindPageDTO::createShared();

	WorkHistoryService service;

	pdto = service.listAll(query);

	vo->success(pdto);

	return vo;
	
}

Uint64JsonVO::Wrapper WorkHistoryController::execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->bm || !dto->gw || !dto->experience || !dto->pimpersonid || !dto->rzjssj || \
		!dto->rzkssj || !dto->ormorgname || !dto->zw || !dto->cfplx || !dto->pimworkhistoryid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	jvo->success(1);

	return jvo;
}

Uint64JsonVO::Wrapper WorkHistoryController::execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimpersonid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	else
	{
		for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
		{
			if (!(*it))
			{
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
				return jvo;
			}
		}
	}

	jvo->success(1);

	return jvo;

}

StringJsonVO::Wrapper WorkHistoryController::execIntoWorkHistory(const String fileBody, const String suffix)
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

	auto jvo = StringJsonVO::createShared();
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("工作履历");
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		//判断文件中是否有数据
		for (int j = 0; j < row.size(); ++j)
		{
			if (row[j].empty())
			{
				jvo->fail("文件不存在");
				return jvo;
			}
			cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}
		cout << endl;


		//添加数据到dto中



	}

	//执行添加逻辑



	jvo->success("文件导入成功");
	return jvo;
}

StringJsonVO::Wrapper WorkHistoryController::execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();

	// 创建测试数据(实际是把数据库的数据放进来)
	vector<vector<std::string>> data;
	stringstream ss1;
	for (int i = 1; i <= 10; i++)
	{
		vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss1.clear();
			// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
			ss1
				<< CharsetConvertHepler::ansiToUtf8("单元格坐标：(") << i
				<< CharsetConvertHepler::ansiToUtf8(",") << j << ")";
			row.push_back(ss1.str());
			ss1.str("");
		}
		data.push_back(row);
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
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// 拼接后缀名
	ss << ".csv";

	std::string fileName = ss.str();
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("工作履历表");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	//测试是否有数据
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		//判断文件中是否有数据
		for (int j = 0; j < row.size(); ++j)
		{
			cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}
		cout << endl;
	}

	// 文件名称
	//std::string fileName = ss.str();
	// 保存文件到目录
	//String fileBody;
	//fileBody.saveToFile(fileName.c_str());

	
	// 测试上传到FastDFS文件服务器
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("192.168.80.129");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://192.168.80.129:8888/" << fieldName;


	cout << ss.str() << endl;
	vo->success(u8"导出成功");
	return vo;
}

