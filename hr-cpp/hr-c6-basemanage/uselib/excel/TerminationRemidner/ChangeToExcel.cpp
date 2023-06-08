#include "stdafx.h"
#include "ChangeToExcel.h"

string ChangeToExcel::changeToExcel(vector<vector<string>>& data)
{
	string fileName = "./public/excel/ReminderContract.xlsx";
	string sheetName = CharsetConvertHepler::ansiToUtf8("数据表1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	return TerminationFastDfs::downloadDfs(fileName);
}
