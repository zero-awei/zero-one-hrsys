#include "stdafx.h"
#include "ExportExcel.h"
#include "ExcelComponent.h"
#include <chrono>
#include <iostream>
#include <iomanip>
using namespace std;

// 注意：为了保证在Linux平台不乱码，需要保证本源码文件的编码为 UTF8 BOM 编码格式
/**
 * 导出数据到Excel文件
 * @param: data将要上传的数据二维向量
 * @return: 返回Excel文件路径
 */
std::string ExportExcel::exportExcel(const std::vector<std::vector<std::string>> &data)
{
	// 定义保存数据位置和页签名称
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
	ss << "-ProjTag.xlsx";

	// 临时文件名称
	std::string fileName = ss.str();
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = "Sheet1";

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	return fileName;
}
