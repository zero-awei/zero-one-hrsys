#include "stdafx.h"
#include "JobTitleInfoDAO.h"
#include "JobTitleInfoMapper.h"
#include "../dao-sql-macro/macro.h"		//自定义的宏文件

inline SqlParams jobtitle_teram_parse(const JobTitleInfoDTO::Wrapper& query,stringstream& sql)
{
	SqlParams params;
	sql << " WHERE 1=1"; 
	SQLPARAMS_STRING_PUSH(EMPLOYEEID);
	SQLPARAMS_STRING_PUSH(CREDENTIALS_NUM);
	SQLPARAMS_STRING_PUSH(EMPLOYEENAME);
	SQLPARAMS_STRING_PUSH(ORGANIZATION_NAME);
	SQLPARAMS_STRING_PUSH(PROFESSORANALYSIS_NAME);
	SQLPARAMS_STRING_PUSH(PROFESSOR_GRADES);
	SQLPARAMS_STRING_PUSH(PROFESSOR_DATE);
	SQLPARAMS_STRING_PUSH(PROFESSIONAL_CATEGORY);
	return params;
}

uint64_t JobTitleInfoDAO::count(const JobTitleInfoDTO::Wrapper& query)
{
    stringstream sql;
	sql << "SELECT COUNT(*) FROM bis_professoranalysis_t";
	SqlParams params = jobtitle_teram_parse(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<JobTitleDo> JobTitleInfoDAO::selectAll(const JobTitleInfoDTO::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM bis_professoranalysis_t";
	SqlParams params = jobtitle_teram_parse(query, sql);
	JobTitleInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<JobTitleDo,JobTitleInfoMapper>(sqlStr,mapper, params);
}

std::vector<std::string> JobTitleInfoDAO::getHead()
{
	// 构建返回对象
	vector<std::string> head;

	string sql = "SELECT COLUMN_NAME	\
		FROM INFORMATION_SCHEMA.COLUMNS	\
		WHERE TABLE_NAME = 'bis_professoranalysis_t'";
	
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

int JobTitleInfoDAO::update(const JobTitleDo& uObj)
{
	stringstream sql;
	stringstream fmts;
	sql << "UPDATE `bis_professoranalysis_t` SET ";
	SQLPARAMS_UPDATE_STRING(name);
	SQLPARAMS_UPDATE_STRING(certid);
	SQLPARAMS_UPDATE_STRING(grades);
	SQLPARAMS_UPDATE_STRING(jobtype);
	SQLPARAMS_UPDATE_STRING(category);
	SQLPARAMS_UPDATE_STRING(getdate);
	SQLPARAMS_UPDATE_STRING(employeeid);
	SQLPARAMS_UPDATE_STRING(employeename);
	SQLPARAMS_UPDATE_STRING(orgname);
	SQLPARAMS_UPDATE_PUSH_FINAL(orgid, "%s", id);
	return sqlSession->executeUpdate(sql.str(), fmts.str().c_str(),
		uObj.getName(),
		uObj.getCertId(),
		uObj.getGrades(),
		uObj.getJobType(),
		uObj.getCategory(),
		uObj.getGetDate(),
		uObj.getEmployeeId(),
		uObj.getEmployeeName(),
		uObj.getOrgName(),
		uObj.getOrgId(),
		uObj.getId());
}
