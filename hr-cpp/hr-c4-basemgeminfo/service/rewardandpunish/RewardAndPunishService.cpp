#include "stdafx.h"
#include "RewardAndPunishService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "../../dao/rewardandpunish/RewardAndPunishDAO.h"

#define DO_TO_VECTOR(f) \
ss.clear(); \
ss<<sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");

RewardAndPunishDTO::Wrapper RewardAndPunishService::listDetail(const RewardAndPunishDetailQuery::Wrapper& query)
{
	RewardAndPunishDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = RewardAndPunishDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), CREATEDATE, _CREATEDATE, UPDATEDATE, _UPDATEDATE, PIMREWARDPUNISHMENTNAME, _PIMREWARDPUNISHMENTNAME, UPDATEMAN, _UPDATEMAN, CREATEMAN, _CREATEMAN, ENABLE, _ENABLE, FJ, _FJ, LX, _LX, CSRQ, _CSRQ, PIMREWARDPUNISHMENTID, _PIMREWARDPUNISHMENTID, PIMPERSONID, _PIMPERSONID, JCJB, _JCJB, JCLX, _JCLX, JLSJ, _JLSJ, CFSJ, _CFSJ, JCJE, _JCJE, JCSJ, _JCSJ, BZ, _BZ, CFLX, _CFLX, JLSS, _JLSS, JLGLBH, _JLGLBH, JLSPZT, _JLSPZT, JLCZZ, _JLCZZ, YXQJSRQ, _YXQJSRQ, DEPARTMENT, _DEPARTMENT, REASON, _REASON);
	}
	return dto;
}

bool RewardAndPunishService::updateData(const RewardAndPunishDTO::Wrapper& dto)
{
	// 组装DO数据
	RewardAndPunishDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _CREATEDATE, CREATEDATE, _UPDATEDATE, UPDATEDATE, _PIMREWARDPUNISHMENTNAME, PIMREWARDPUNISHMENTNAME, _UPDATEMAN, UPDATEMAN, _CREATEMAN, CREATEMAN, _ENABLE, ENABLE, _FJ, FJ, _LX, LX, _CSRQ, CSRQ, _PIMREWARDPUNISHMENTID, PIMREWARDPUNISHMENTID, _PIMPERSONID, PIMPERSONID, _JCJB, JCJB, _JCLX, JCLX, _JLSJ, JLSJ, _CFSJ, CFSJ, _JCJE, JCJE, _JCSJ, JCSJ, _BZ, BZ, _CFLX, CFLX, _JLSS, JLSS, _JLGLBH, JLGLBH, _JLSPZT, JLSPZT, _JLCZZ, JLCZZ, _YXQJSRQ, YXQJSRQ, _DEPARTMENT, DEPARTMENT, _REASON, REASON);
	// 执行数据修改
	RewardAndPunishDAO dao;
	return dao.update(data) == 1;
}

string RewardAndPunishService::download(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	vector<vector<string>> data;
	list<RewardAndPunishDO> result = RewardAndPunishDAO().selectWithPage(query);
	data.push_back({
		ZH_WORDS_GETTER("rewardandpunish.createdate"),
		ZH_WORDS_GETTER("rewardandpunish.updatedate"),
		ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentname"),
		ZH_WORDS_GETTER("rewardandpunish.updateman"),
		ZH_WORDS_GETTER("rewardandpunish.createman"),
		ZH_WORDS_GETTER("rewardandpunish.enable"),
		ZH_WORDS_GETTER("rewardandpunish.fj"),
		ZH_WORDS_GETTER("rewardandpunish.lx"),
		ZH_WORDS_GETTER("rewardandpunish.csrq"),
		ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentid"),
		ZH_WORDS_GETTER("rewardandpunish.pimpersonid"),
		ZH_WORDS_GETTER("rewardandpunish.jcjb"),
		ZH_WORDS_GETTER("rewardandpunish.jclx"),
		ZH_WORDS_GETTER("rewardandpunish.jlsj"),
		ZH_WORDS_GETTER("rewardandpunish.cfsj"),
		ZH_WORDS_GETTER("rewardandpunish.jcje"),
		ZH_WORDS_GETTER("rewardandpunish.jcsj"),
		ZH_WORDS_GETTER("rewardandpunish.bz"),
		ZH_WORDS_GETTER("rewardandpunish.cflx"),
		ZH_WORDS_GETTER("rewardandpunish.jlss"),
		ZH_WORDS_GETTER("rewardandpunish.jlglbh"),
		ZH_WORDS_GETTER("rewardandpunish.jlspzt"),
		ZH_WORDS_GETTER("rewardandpunish.jlczz"),
		ZH_WORDS_GETTER("rewardandpunish.yxqjsrq"),
		ZH_WORDS_GETTER("rewardandpunish.department"),
		ZH_WORDS_GETTER("rewardandpunish.reason")
		});
	for (RewardAndPunishDO sub : result)
	{
		vector<string> row;
		stringstream ss;
		DO_TO_VECTOR(_UPDATEDATE);
		DO_TO_VECTOR(_CREATEDATE);
		DO_TO_VECTOR(_PIMREWARDPUNISHMENTNAME);
		DO_TO_VECTOR(_UPDATEMAN);
		DO_TO_VECTOR(_CREATEMAN);
		DO_TO_VECTOR(_ENABLE);
		DO_TO_VECTOR(_FJ);
		DO_TO_VECTOR(_LX);
		DO_TO_VECTOR(_CSRQ);
		DO_TO_VECTOR(_PIMREWARDPUNISHMENTID);
		DO_TO_VECTOR(_PIMPERSONID);
		DO_TO_VECTOR(_JCJB);
		DO_TO_VECTOR(_JCLX);
		DO_TO_VECTOR(_JLSJ);
		DO_TO_VECTOR(_CFSJ);
		DO_TO_VECTOR(_JCJE);
		DO_TO_VECTOR(_JCSJ);
		DO_TO_VECTOR(_BZ);
		DO_TO_VECTOR(_CFLX);
		DO_TO_VECTOR(_JLSS);
		DO_TO_VECTOR(_JLGLBH);
		DO_TO_VECTOR(_JLSPZT);
		DO_TO_VECTOR(_JLCZZ);
		DO_TO_VECTOR(_YXQJSRQ);
		DO_TO_VECTOR(_DEPARTMENT);
		DO_TO_VECTOR(_REASON);

		data.push_back(row);
	}
	stringstream ss;
	ss << "./temp/excel/" << chrono::system_clock::now().time_since_epoch().count() << ".xlsx";
	string fileName = ss.str();
	string sheetName = CharsetConvertHepler::ansiToUtf8("sheet1");
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
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15:8888/" << fieldName;


	//cout << ss.str() << endl;

	return ss.str();
}