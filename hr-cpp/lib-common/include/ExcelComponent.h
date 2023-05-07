#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:33:44
 
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
#ifndef _EXCELCOMPONENT_H_
#define _EXCELCOMPONENT_H_
#include <xlnt/xlnt.hpp>
#include <string>
#include <vector>
/**
 * Excel组件
 * 注意：xlnt只支持xlsx文件格式
 */
class ExcelComponent
{
private:
	xlnt::workbook wb;
	xlnt::worksheet sheet;
	// 行高
	double rowHeight = 20;
	// 列宽
	double colWidth = 20;
	// 创建Sheet
	void createSheet(const std::string& sheetName);
public:
	ExcelComponent();
	// 设置行高
	void setRowHeight(double rowHeight);
	// 设置列宽
	void setColWidth(double colWidth);
	// 清空工作薄
	void clearWorkbook();
	
	//************************************
	// Method:    readIntoVector
	// FullName:  ExcelComponent::readIntoVector
	// Access:    public 
	// Returns:   std::vector<std::vector<std::string>> 指定页签内容的二维vector
	// Qualifier: 读取指定文件指定页签的内容
	// Parameter: const std::string & fileName 文件名称的全路径，注意文件路径分隔符使用/
	// Parameter: const std::string & sheetName 页签名称
	//************************************
	std::vector<std::vector<std::string>> readIntoVector(const std::string& fileName, const std::string& sheetName);
	
	//************************************
	// Method:    writeVectorToFile
	// FullName:  ExcelComponent::writeVectorToFile
	// Access:    public 
	// Returns:   void
	// Qualifier: 新增内容到指定页签，并保存到文件中
	// Parameter: const std::string & fileName 文件名称的全路径，注意文件路径分隔符使用/
	// Parameter: const std::string & sheetName 新增内容保存到的页签名称
	// Parameter: const std::vector<std::vector<std::string>> & data 新增保存的数据
	//************************************
	void writeVectorToFile(const std::string& fileName, const std::string& sheetName, const std::vector<std::vector<std::string>>& data);
};
#endif // _EXCELCOMPONENT_H_
