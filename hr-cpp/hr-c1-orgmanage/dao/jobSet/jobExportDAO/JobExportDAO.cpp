#include "stdafx.h"
#include "JobExportDAO.h"

std::list<PostDetailDO> JobExportDAO::exportJobInfo(const PostDetailQuery::Wrapper& query)
{
	stringstream sqltmp;
	sqltmp << "SELECT `ORMPOSTID`, `ORMPOSTNAME`, `ISKEYPOSTION`, `CREATEMAN`, ";
	sqltmp << "`UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`, `GWTYPE`, `GWFL`, `ISCONFIDENTIAL`, ";
	sqltmp << "`ISTEMP`, `POSTNATURE`, `STARTSTOPSIGN`";
	
	string sql = sqltmp.str();

	JobExportMapper mapper;

	return sqlSession->executeQuery<PostDetailDO, JobExportMapper>(sql, mapper);
}
