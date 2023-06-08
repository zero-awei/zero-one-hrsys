#include "stdafx.h"
#include "JobTitleInformationDAO.h"
#include "JobTitleInformationMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define JOBTITLE_INFORMATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->employeeid) { \
	sql << " AND `EMPLOYEEID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->employeeid.getValue("")); \
}
//统计职称的记录数
uint64_t JobTitleInformationDAO::count(const JobTitleInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `bis_professoranalysis_t`";
	JOBTITLE_INFORMATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//职称分页查询函数
list<JobTitleInformationDO> JobTitleInformationDAO::selectWithPage(const JobTitleInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT a.professoranalysis_name,a.credentials_num,a.professor_grades,a.major,b.zchqrq,b.reviewbody,b.lssuingagency,b.employtime,b.enable,a.employeeid FROM `bis_professoranalysis_t` a left join `t_pimtitle` b on a.credentials_num=b.zcbh   ";
	JOBTITLE_INFORMATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	JobTitleInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<JobTitleInformationDO, JobTitleInformationMapper>(sqlStr, mapper, params);
}