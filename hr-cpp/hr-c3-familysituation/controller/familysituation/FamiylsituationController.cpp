#include "stdafx.h"
#include "FastDfsClient.h"
#include "FamilysituationController.h"

// 分页查询响应
FamilySituationPageJsonVO::Wrapper FamilysituationController::execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query)
{
	auto vo = FamilySituationPageJsonVO::createShared();
	//待补充
	return vo;
}

// 指定查询响应
FamilysituationJsonVO::Wrapper FamilysituationController::execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query)
{
	auto vo = FamilysituationJsonVO::createShared();
	//待补充
	return vo;
}


// 添加响应
StringJsonVO::Wrapper FamilysituationController::execAddFamilysituation(const FamilysituationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("add success");
	return vo;
}

// 修改响应
StringJsonVO::Wrapper FamilysituationController::execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success(dto->name);
	return vo;
}

// 删除响应
StringJsonVO::Wrapper FamilysituationController::execRemoveFamilysituation(const FamilysituationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success(dto->name);
	return vo;
}

// 导入响应
StringJsonVO::Wrapper FamilysituationController::executeImportFamilysituation(const String& fileBody, const String& suffix)
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

//	// 测试上传到FastDFS文件服务器
//#ifdef LINUX
//	//定义客户端对象
//	FastDfsClient client("conf/client.conf", 3);
//#else
//	//定义客户端对象
//	FastDfsClient client("192.168.52.133");
//#endif
//	std::string fieldName = client.uploadFile(fileName);
//	std::cout << "upload fieldname is : " << fieldName << std::endl;
//	ss.str("");
//	ss.clear();
//	ss << "http://192.168.52.133:8888/" << fieldName;

	// excel解析逻辑（暂时不会写）
	
	// 创建响应数据
	auto vo = StringJsonVO::createShared();
	vo->success(String("cool"));
	return vo;
}


// 导出响应
StringJsonVO::Wrapper FamilysituationController::execExportFamilysituation(const String& url)
{
	auto vo = StringJsonVO::createShared();
	//待补充 返回一个地址
	return vo;
}

