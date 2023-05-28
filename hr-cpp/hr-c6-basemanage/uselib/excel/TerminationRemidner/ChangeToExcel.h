#pragma once
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "uselib/fastdfs/TerminationReminder/TerminationRemidnerFastdfs.h"
#include <vector>
using namespace std;
class ChangeToExcel
{
public:
	static string changeToExcel(vector<vector<string>>&data);
};