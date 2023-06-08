#include "stdafx.h"
#include "JobExportDAO.h"

std::list<PostDetailDO> JobExportDAO::exportJobInfo(const PostDetailQuery::Wrapper& query)
{
	stringstream sqltmp;
	sqltmp << "SELECT `ORMPOSTID`, `ORMPOSTNAME`, `ISKEYPOSTION`, `CREATEMAN`, ";
	sqltmp << "`UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`, `GWTYPE`, `GWFL`, `ISCONFIDENTIAL`, ";
	sqltmp << "`ISTEMP`, `POSTNATURE`, `STARTSTOPSIGN`, `ISTEMP`, `NX`, `BXJLNX`, `XH`, `LGNX`, `QZLGNX` FROM `t_ormpost`";
	sqltmp << "ORDER BY `XH` ";
	string sql = sqltmp.str();
	if (query->sortTypeAndMethod == "DESC") {
		string sql = sqltmp.str() + " DESC";
	}
	else if(query->sortTypeAndMethod == "ASC"){
		string sql = sqltmp.str() + " ASC";
	}
	//统计岗位信息数量
	stringstream sqlcount;
	sqlcount << "SELECT COUNT(`ORMPOSTID`) FROM `t_ormpost`";
	string count = sqlcount.str();
	uint64_t infoCount=sqlSession->executeQueryNumerical(count);
	//限制导出数量
	if (infoCount) {
		if (infoCount > 5000) {
			infoCount = 5000;
			sql += " LIMIT " + to_string(infoCount);
		}

	}

	JobExportMapper mapper;

	return sqlSession->executeQuery<PostDetailDO, JobExportMapper>(sql, mapper);
}

vector<std::string> JobExportDAO::getJobInfoHead()
{
	// 构建返回对象
	vector<std::string> head;

	string sql = "SELECT COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_NAME = 't_ormpost' ORDER BY ORDINAL_POSITION";
	Statement* st = sqlSession->getConnection()->createStatement();
	ResultSet* res;

	res = st->executeQuery(sql);
	while (res->next())
	{
		head.push_back(res->getString(1));
	}

	st->close();
	res->close();
	return head;
}
