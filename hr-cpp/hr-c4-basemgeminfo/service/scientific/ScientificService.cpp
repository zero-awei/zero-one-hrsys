#include "stdafx.h"
#include "ScientificService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "../../dao/scientific/ScientificDAO.h"

#define DO_TO_VECTOR(f) \
ss.clear(); \
ss<<sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");

ScientificDTO::Wrapper ScientificService::listDetail(const ScientificViewQuery::Wrapper& query)
{
	// 构建返回对象
	ScientificDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = ScientificDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), updateman, Updateman, pimresearchfindingsname, Pimresearchfindingsname, fj, Fj, enable, Enable, createdate, Createdate, updatedate, Updatedate, createman, Createman, pimresearchfindingsid, Pimresearchfindingsid, pimpersonid, Pimpersonid, hqsj, Hqsj, jlss, Jlss, jlglbh, Jlglbh, jlczz, Jlczz, reason, Reason);
	}
	return dto;
}

bool ScientificService::updateData(const ScientificDTO::Wrapper& dto)
{
	// 组装DO数据
	ScientificDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Updateman, updateman, Pimresearchfindingsname, pimresearchfindingsname, Fj, fj, Enable, enable, Createdate, createdate, Updatedate, updatedate, Createman, createman, Pimresearchfindingsid, pimresearchfindingsid, Pimpersonid, pimpersonid, Hqsj, hqsj, Jlss, jlss, Jlglbh, jlglbh, Jlczz, jlczz, Reason, reason);
	// 执行数据修改
	ScientificDAO dao;
	return dao.update(data) == 1;
}

string ScientificService::download(const ScientificDownloadQuery::Wrapper& query)
{
	vector<vector<string>> data;
	list<ScientificDO> result = ScientificDAO().selectWithPage(query);
	data.push_back({
		CharsetConvertHepler::ansiToUtf8("更新人") ,
		CharsetConvertHepler::ansiToUtf8("科研成果名称") ,
		CharsetConvertHepler::ansiToUtf8("附件") ,
		CharsetConvertHepler::ansiToUtf8("ENABLE") ,
		CharsetConvertHepler::ansiToUtf8("建立时间") ,
		CharsetConvertHepler::ansiToUtf8("更新时间") ,
		CharsetConvertHepler::ansiToUtf8("建立人") ,
		CharsetConvertHepler::ansiToUtf8("科研成果标识") ,
		CharsetConvertHepler::ansiToUtf8("人员信息标识") ,
		CharsetConvertHepler::ansiToUtf8("获取时间") ,
		CharsetConvertHepler::ansiToUtf8("记录所属") ,
		CharsetConvertHepler::ansiToUtf8("记录管理编号") ,
		CharsetConvertHepler::ansiToUtf8("记录操作者") ,
		CharsetConvertHepler::ansiToUtf8("拒绝原因")
		});
	for (ScientificDO sub : result)
	{
		vector<string> row;
		stringstream ss;
		DO_TO_VECTOR(Updateman);
		DO_TO_VECTOR(Pimresearchfindingsname);
		DO_TO_VECTOR(Fj);
		DO_TO_VECTOR(Enable);
		DO_TO_VECTOR(Createdate);
		DO_TO_VECTOR(Updatedate);
		DO_TO_VECTOR(Createman);
		DO_TO_VECTOR(Pimresearchfindingsid);
		DO_TO_VECTOR(Pimpersonid);
		DO_TO_VECTOR(Hqsj);
		DO_TO_VECTOR(Jlss);
		DO_TO_VECTOR(Jlglbh);
		DO_TO_VECTOR(Jlczz);
		DO_TO_VECTOR(Reason);
		data.push_back(row);
	}
	stringstream ss;
	ss << "./temp/excel/" << chrono::system_clock::now().time_since_epoch().count() << ".xlsx";
	string fileName = ss.str();
	string sheetName = CharsetConvertHepler::ansiToUtf8("数据表1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("192.168.88.1");
#endif
	//上传excel结果
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://192.168.88.1:8888/" << fieldName;


	//cout << ss.str() << endl;

	return ss.str();
}
