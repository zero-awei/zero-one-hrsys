#include "stdafx.h"
#include "LegalEntityMaiController.h"
#include "service/LegalEntityMai/LegalEntityMaiService.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "FastDfsClient.h"
#include "tree/TreeUtil.h"
#include "../include/ExcelComponent.h"
#include "CommonMacros.h"

/* 法人主体维护控制器具体实现--（组织管理-数据设置-法人主体维护）--TripleGold */

LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// 定义一个Service
	LegalEntityMaiService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LegalEntityMaiPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	//auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (dto->ORMSIGNORGID == "") {

	//}
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->ORMSIGNORGID || dto->ORMSIGNORGID == "") {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LegalEntityMaiService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->ORMSIGNORGID);
	}
	else {
		jvo->fail(dto->ORMSIGNORGID);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execAddLEM(const List<LegalEntityMaiAddDTO::Wrapper>& dtoList, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	int length = dtoList->size();
	// 参数检验
	if (length <= 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dtoList->begin(); it != dtoList->end(); it++)
	{
		if (!(*it)) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// 定义一个Service
	LegalEntityMaiService service;
	bool res = true;
	for (auto it = dtoList->begin(); it != dtoList->end(); it++)
	{
		if (!service.saveData(*it, payload)) {
			res = false;
		}
	}
	// 只要有一个插入失败即返回fail
	if (res) jvo->success(1);
	else jvo->fail(1);

	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execRemoveLEM(const LegalEntityMaiDelDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->Ids->size();
	// 参数检验
	if (length <= 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->Ids->begin(); it != dto->Ids->end(); it++)
	{
		if (!(*it)) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	// 定义一个Service
	LegalEntityMaiService service;
	if (service.deleteById(dto)) {
		jvo->success(1);
	}
	else {
		jvo->fail(1);
	}
	// 响应结果
	return jvo;
}

void directory(const string fileName) {
	//判断目录是否存在，不存在创建目录
	auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
	const size_t dirLen = dir.length();
	if (dirLen > MAX_DIR_LEN)
	{
		std::cout << "ExcelComponent 135: excel save fail(file path too long)" << std::endl;
		return;
	}
	char tmpDirPath[MAX_DIR_LEN] = { 0 };
	for (size_t i = 0; i < dirLen; i++)
	{
		tmpDirPath[i] = dir[i];
		if (tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				if (MKDIR(tmpDirPath) != 0)
				{
					std::cout << "ExcelComponent 148: excel save fail(create dir " << tmpDirPath << " fail)" << std::endl;
					return;
				}
			}
		}
	}
}

StringJsonVO::Wrapper LegalEntityMaiController::execImportLEM(const String& body, const String& suffix, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!body || body->empty() || !suffix || suffix->empty()) {
		jvo->fail("fail to import");
	}

	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/excel/";

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
	// 如果文件目录不存在，添加目录
	directory(fileName);
	// 保存文件到临时目录
	body.saveToFile(fileName.c_str());

	// 定义一个Service
	LegalEntityMaiService service;
	service.savaBatchDataWithFile(fileName, payload);
	// 响应结果
	jvo->success(String(ss.str().c_str()));
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execExportLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	LegalEntityMaiService service;
	// 执行文件导出
	std::string fileName = service.exportFile(query);
	if (fileName.empty()) {
		jvo->fail("fail to export");
	}
	else {
		jvo->success(fileName);
	}
	// 响应结果
	return jvo;
}