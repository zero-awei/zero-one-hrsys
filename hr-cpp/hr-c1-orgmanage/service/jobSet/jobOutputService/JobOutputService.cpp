#include "stdafx.h"
#include "JobOutputService.h"
#include "dao/jobSet/jobExportDAO/JobExportDAO.h"
#include "ExcelComponent.h"
#include "uselib/excel/ExportExcel.h"
#include "uselib/fastdfs/UseFastDfs.h"

std::string JobOutputService::exportJobInfomation(const PostDetailQuery::Wrapper& query)
{
	JobExportDAO dao;
	auto res = dao.exportJobInfo(query);

	ExportExcel excel;

	vector<vector<string>> data;
	for (auto item : res)
	{
		vector<string> tmp;
		tmp.push_back(item.getOrmPostId());
		tmp.push_back(item.getOrmPostName());
		tmp.push_back(item.getCreateMan());
		tmp.push_back(item.getUpdateDate());
		tmp.push_back(item.getUpdateMan());
		tmp.push_back(item.getCreateDate());
		tmp.push_back(to_string(item.getXh()));
		tmp.push_back(item.getOrmOrgId());
		tmp.push_back(item.getGwType());
		tmp.push_back(item.getGwfl());
		tmp.push_back(item.getIsConfidential());
		tmp.push_back(item.getIsTemp());
		tmp.push_back(to_string(item.getNx()));
		tmp.push_back(to_string(item.getBxjlnx()));
		tmp.push_back(item.getIsKeyPostion());
		tmp.push_back(item.getPostNature());
		tmp.push_back(item.getStartStopSign());
		data.push_back(tmp);
	}

	// 生成数据表表头
	vector<string> head = dao.getJobInfoHead();
	head.erase(head.begin() + 8, head.begin() + 10);

	// 导出到Excel文件
	data.insert(data.begin(), head);
	string fileName = excel.exportExcel(data);

	// TODO: 上传到FastDFS文件服务器, 返回下载链接
	UseFastDfs dfs;
	string url = dfs.uploadWithNacos(fileName);

	return url;
}
