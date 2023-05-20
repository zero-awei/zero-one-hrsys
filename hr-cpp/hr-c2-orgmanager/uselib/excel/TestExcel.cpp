
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:32:20

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "TestExcel.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
using namespace std;
// 注意：为了保证在Linux平台不乱码，需要保证本源码文件的编码为 UTF8 BOM 编码格式
void TestExcel::testExcel()
{
	// 创建测试数据
	vector<vector<std::string>> data;
	stringstream ss;
	for (int i = 1; i <= 10; i++)
	{
		vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
			ss
				<< CharsetConvertHepler::ansiToUtf8("单元格坐标：(") << i
				<< CharsetConvertHepler::ansiToUtf8(",") << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = "./public/excel/1.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("数据表1");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// 注意：这里使用了编码转换，目的是为了在控制台打印显示不乱码，如果是将数据写入数据库，那么就不需要再进行编码转换了
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
	}

	// 测试创建第二个页签
	sheetName = CharsetConvertHepler::ansiToUtf8("数据表2");
	excel.writeVectorToFile(fileName, sheetName, data);

	// 测试覆盖第一个页签
	sheetName = CharsetConvertHepler::ansiToUtf8("数据表1");
	data.insert(data.begin(), {
		CharsetConvertHepler::ansiToUtf8("表头1") ,
		CharsetConvertHepler::ansiToUtf8("表头2") ,
		CharsetConvertHepler::ansiToUtf8("表头3") ,
		CharsetConvertHepler::ansiToUtf8("表头4") ,
		CharsetConvertHepler::ansiToUtf8("表头5") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);
}
