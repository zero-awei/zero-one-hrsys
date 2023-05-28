
#include "stdafx.h"
#include "JobTitleDAO.h"
#include "JobTitleMapper.h"
#include "SqlSession.h"
#include "JobTitleDAO.h"
#include <sstream>
#include <domain/dto/JobTitle/JobTitleDTO.h>

#define SAMPLE_QUERY_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1 "; \
if (query->param) { \
	sql << "and employee_id like concat('%',?,'%') ";\
	SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));\
    sql<< "or employee_name like concat('%',?,'%')";\
    SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));\
}

uint64_t JobTitleDAO::count(const JobTitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select count(*) from `test` ";
	// 查看是否有参数，如果有带上参数查询
	SqlParams params;
	if (query->param) {
		cout << "携带参数:" << query->param.getValue("") << endl;
		sql << "where employee_id like concat('%',?,'%') ";
		SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));
		sql << "or employee_name like concat('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));
	}
	else {
		string sqlStr = sql.str();
		cout << "sql语句：" << sqlStr << endl;
		return sqlSession->executeQueryNumerical(sqlStr);
	}
	string sqlStr = sql.str();
	cout << "sql语句：" << sqlStr << endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<JobTitleDO> JobTitleDAO::selectAll(const JobTitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select * from `test`";
	// 查看是否有参数，如果有带上参数查询
	SAMPLE_QUERY_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	string sqlStr = sql.str();
	JobTitleMapper mapper;
	if (!query->param) {
		cout << "sql语句：" << sqlStr << endl;
		return sqlSession->executeQuery<JobTitleDO, JobTitleMapper>(sqlStr, mapper);
	}
	cout << "sql语句：" << sqlStr << endl;
	return sqlSession->executeQuery<JobTitleDO, JobTitleMapper>(sqlStr, mapper, params);
}

/** 新增职称信息 */
uint64_t JobTitleDAO::addTitle(const JobTitleDO& aObj)
{
	string sql = "insert into `test` (`employee_id`,`employee_name`,`jobtitle_name`,`get_time`,`employee_state`,`org_name`,`certificate_id`,";
	sql += "`jobtitle_grades`,`professional_cate`,`professional_name`,`issuing_authority`,`judging_unit`,`title_employment_time`,`b_highest_professional_title`) ";
	sql += "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	// 附加参数
	SqlParams params;
	SQLPARAMS_PUSH(params, "i", int, aObj.getEmployee_Id());
	SQLPARAMS_PUSH(params, "s", string, aObj.getEmployee_Name());
	SQLPARAMS_PUSH(params, "s", string, aObj.getJobtitle_Name());
	SQLPARAMS_PUSH(params, "s", string, aObj.getGet_Time());
	SQLPARAMS_PUSH(params, "s", string, aObj.getEmployee_State());
	SQLPARAMS_PUSH(params, "s", string, aObj.getOrg_Name());
	SQLPARAMS_PUSH(params, "i", int, aObj.getCertificate_Id());
	SQLPARAMS_PUSH(params, "s", string, aObj.getJobtitle_Grades());
	SQLPARAMS_PUSH(params, "s", string, aObj.getProfessional_Cate());
	SQLPARAMS_PUSH(params, "s", string, aObj.getProfessional_Name());
	SQLPARAMS_PUSH(params, "s", string, aObj.getIssuing_Authority());
	SQLPARAMS_PUSH(params, "s", string, aObj.getJudging_Unit());
	SQLPARAMS_PUSH(params, "s", string, aObj.getTitle_Employment_Time());
	SQLPARAMS_PUSH(params, "s", string, aObj.getB_Highest_Professional_Title());
	cout << "employee_name:" << aObj.getEmployee_Name() << endl;
	return sqlSession->executeInsert(sql, params);
}

// 支持批量删除
uint64_t JobTitleDAO::removeById(const JobTitleDeleteDTO::Wrapper& list)
{
	// 创建批量删除sql,拼接sql
	stringstream sql;
	sql << "delete from `test` where id in (";
	SqlParams params;
	auto it = list->list_jobtitle_id->begin();
	while (it != list->list_jobtitle_id->end()) {
		sql << "?";
		SQLPARAMS_PUSH(params, "i", int, (*it).getValue(0));
		if (++it == list->list_jobtitle_id->end()) {
			// 中断，不加，
			break;
		}
		// 加，
		sql << ",";
	}
	// 加右括号
	sql << ")";
	string sqlStr = sql.str();
	cout << "sql语句：" << sqlStr << endl;
	return sqlSession->executeUpdate(sqlStr, params);
}


