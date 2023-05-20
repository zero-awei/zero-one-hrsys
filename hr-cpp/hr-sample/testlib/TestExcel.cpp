/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/10 22:03:59

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
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
using namespace std;

void TestExcel::test()
{
	// ������������
	vector<vector<std::string>> data;
	stringstream ss;
	for (int i = 1; i <= 10; i++)
	{
		vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
			ss
				<< CharsetConvertHepler::ansiToUtf8("��Ԫ�����꣺(") << i
				<< CharsetConvertHepler::ansiToUtf8(",") << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	// ע�⣺�ļ������ƺ��ļ�·�����ܳ�������
	std::string fileName = "./public/excel/1.xlsx";
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�1");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// ע�⣺����ʹ���˱���ת����Ŀ����Ϊ���ڿ���̨��ӡ��ʾ�����룬����ǽ�����д�����ݿ⣬��ô�Ͳ���Ҫ�ٽ��б���ת����
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
	}

	// ���Դ����ڶ���ҳǩ
	sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�2");
	excel.writeVectorToFile(fileName, sheetName, data);

	// ���Ը��ǵ�һ��ҳǩ
	sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�1");
	data.insert(data.begin(), {
		CharsetConvertHepler::ansiToUtf8("��ͷ1") ,
		CharsetConvertHepler::ansiToUtf8("��ͷ2") ,
		CharsetConvertHepler::ansiToUtf8("��ͷ3") ,
		CharsetConvertHepler::ansiToUtf8("��ͷ4") ,
		CharsetConvertHepler::ansiToUtf8("��ͷ5") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);
}
