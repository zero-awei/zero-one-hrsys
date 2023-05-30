#include "stdafx.h"
#include "ContractController.h"
#include "service/akieService/ContractInfoService.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// ������Ӧ����
	auto vo = ContractJsonVO_::createShared();

	auto data = ContractDTO_::createShared();
	// 非空校验
	if (!query->id)
	{
		vo->init(data, RS_PARAMS_INVALID);
		return vo;
	}
	ContractInfoService service;

	auto dto = service.listContract(query);

	// 响应结果
	vo->success(dto);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// 非空校验
	if (!dto->id || !dto->name || !dto->type || !dto->variety || !dto->date || !dto->condition || !dto->department_m || !dto->department_c || !dto->date_end)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//创建service对象
	ContractInfoService service;

	// 执行数据修改
	if (service.updateContract(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;
}

StringJsonVO::Wrapper ContractController::execUploadContract(const String& fileBody, const String& suffix)
{
	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/file/";

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

	//读取excel
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("Sheet1");
	ExcelComponent excel;
	auto readData = excel.readIntoVector(fileName, sheetName);

	//创建dto
	auto dto = ContractDTO_::createShared();
	//创建service
	ContractInfoService service;
	//显示excel数据
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// 注意：这里使用了编码转换，目的是为了在控制台打印显示不乱码，如果是将数据写入数据库，那么就不需要再进行编码转换了
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
		dto->name = row[0];
		string tmp = row[1];
		dto->id = tmp.c_str();
		dto->type = row[2];
		dto->variety = row[3];
		dto->date = row[4];
		dto->condition = row[5];
		dto->department_m = row[6];
		dto->department_c = row[7];
		dto->date_end = row[8];
		dto->tip = row[9];
		service.saveData(dto);
	}

	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));

	return vo;
}



StringJsonVO::Wrapper ContractController::execDownloadContract(const ContractDownloadQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();


	// 校验
	if (query->sequence->empty() || query->sequence != "ASC" && query->sequence != "DESC")
	{
		vo->init("error(contact akie)", RS_PARAMS_INVALID);
		return vo;
	}

	// 最大5000条
	if (query->rows > 5000)
		query->rows = 5000;

	//创建service对象
	ContractInfoService service;
	string url = service.downloadContract(query);

	std::cout << url;
	//判断url是否为空
	if (url.empty())
		vo->fail(url);
	else
		vo->success(url);
	return vo;
}
