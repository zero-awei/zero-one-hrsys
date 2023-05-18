#include "stdafx.h"
#include "MilitaryService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "../../dao/military/MilitaryDAO.h"

#define DO_TO_VECTOR(f) \
ss.clear(); \
ss<<sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");

MilitaryDTO::Wrapper MilitaryService::listDetail(const MilitaryDetailQuery::Wrapper& query)
{
	// 构建返回对象
	//auto lists = MilitaryDTO::createShared();
	MilitaryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = MilitaryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), UPDATEDATE, _UPDATEDATE, PIMARMYCADRESNAME, _PIMARMYCADRESNAME, FJ, _FJ, CREATEDATE, _CREATEDATE, UPDATEMAN, _UPDATEMAN, ENABLE, _ENABLE, PIMARMYCADRESID, _PIMARMYCADRESID, CREATEMAN, _CREATEMAN, PIMPERSONID, _PIMPERSONID, FSSJ, _FSSJ, JLSS, _JLSS, JLSPZT, _JLSPZT, JLGLBH, _JLGLBH, JLCZZ, _JLCZZ, TROOPTYPE, _TROOPTYPE, LEVELTYPE, _LEVELTYPE, REASON, _REASON);
	}
	return dto;
}

bool MilitaryService::updateData(const MilitaryDTO::Wrapper& dto)
{
	// 组装DO数据
	MilitaryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _UPDATEDATE, UPDATEDATE, _PIMARMYCADRESNAME, PIMARMYCADRESNAME, _FJ, FJ, _CREATEDATE, CREATEDATE, _UPDATEMAN, UPDATEMAN, _ENABLE, ENABLE, _PIMARMYCADRESID, PIMARMYCADRESID, _CREATEMAN, CREATEMAN, _PIMPERSONID, PIMPERSONID, _FSSJ, FSSJ, _JLSS, JLSS, _JLSPZT, JLSPZT, _JLGLBH, JLGLBH, _JLCZZ, JLCZZ, _TROOPTYPE, TROOPTYPE, _LEVELTYPE, LEVELTYPE, _REASON, REASON);
	// 执行数据修改
	MilitaryDAO dao;
	return dao.update(data) == 1;
}

string MilitaryService::download(const MilitaryDownloadQuery::Wrapper& query)
{
	vector<vector<string>> data;
	list<MilitaryDO> result = MilitaryDAO().selectWithPage(query);
	data.push_back({
		CharsetConvertHepler::ansiToUtf8("更新时间") ,
		CharsetConvertHepler::ansiToUtf8("军转干部名称") ,
		CharsetConvertHepler::ansiToUtf8("附件") ,
		CharsetConvertHepler::ansiToUtf8("建立时间") ,
		CharsetConvertHepler::ansiToUtf8("更新人") ,
		CharsetConvertHepler::ansiToUtf8("ENABLE") ,
		CharsetConvertHepler::ansiToUtf8("军转干部标识") ,
		CharsetConvertHepler::ansiToUtf8("建立人") ,
		CharsetConvertHepler::ansiToUtf8("人员信息标识") ,
		CharsetConvertHepler::ansiToUtf8("发生时间") ,
		CharsetConvertHepler::ansiToUtf8("记录所属") ,
		CharsetConvertHepler::ansiToUtf8("审批状态") ,
		CharsetConvertHepler::ansiToUtf8("记录管理编号") ,
		CharsetConvertHepler::ansiToUtf8("记录操作者") ,
		CharsetConvertHepler::ansiToUtf8("类型") ,
		CharsetConvertHepler::ansiToUtf8("级别") ,
		CharsetConvertHepler::ansiToUtf8("拒绝原因")
	});
	for (MilitaryDO sub : result)
	{
		vector<string> row;
		stringstream ss;
		DO_TO_VECTOR(_UPDATEDATE);
		DO_TO_VECTOR(_PIMARMYCADRESNAME);
		DO_TO_VECTOR(_FJ);
		DO_TO_VECTOR(_CREATEDATE);
		DO_TO_VECTOR(_UPDATEMAN);
		DO_TO_VECTOR(_ENABLE);
		DO_TO_VECTOR(_PIMARMYCADRESID);
		DO_TO_VECTOR(_CREATEMAN);
		DO_TO_VECTOR(_PIMPERSONID);
		DO_TO_VECTOR(_FSSJ);
		DO_TO_VECTOR(_JLSS);
		DO_TO_VECTOR(_JLSPZT);
		DO_TO_VECTOR(_JLGLBH);
		DO_TO_VECTOR(_JLCZZ);
		DO_TO_VECTOR(_TROOPTYPE);
		DO_TO_VECTOR(_LEVELTYPE);
		DO_TO_VECTOR(_REASON);
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
	FastDfsClient client("8.130.87.15");
#endif
	//上传excel结果
	string filedName = client.uploadFile(fileName);
	cout << "upload fieldname is : " << filedName << endl;
	//删除上传的文件
	//cout << "delete file result is : " << client.deleteFile(filedName) << endl;
	return filedName;
}
