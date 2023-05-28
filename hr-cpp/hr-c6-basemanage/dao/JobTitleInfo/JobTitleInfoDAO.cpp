#include "stdafx.h"
#include "JobTitleInfoDAO.h"
#include "JobTitleInfoMapper.h"
#include "../dao-sql-macro/macro.h"		//自定义的宏文件

inline SqlParams jobtitle_teram_parse(const JobTitleInfoDTO::Wrapper& query,stringstream& sql)
{
	SqlParams params;
	sql << " WHERE 1=1"; 
	SQLPARAMS_INT_PUSH(EMPLOYEEID);
	SQLPARAMS_INT_PUSH(CREDENTIALS_NUM);
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

int JobTitleInfoDAO::update(const JobTitleInfoDTO& uObj)
{
	stringstream sql;
	stringstream fmts;
	sql << "UPDATE `bis_professoranalysis_t` SET ";
	SQLPARAMS_UPDATE_INT(EMPLOYEEID);
	SQLPARAMS_UPDATE_INT(CREDENTIALS_NUM);
	SQLPARAMS_UPDATE_STRING(EMPLOYEENAME);
	SQLPARAMS_UPDATE_STRING(ORGANIZATION_NAME);
	SQLPARAMS_UPDATE_STRING(PROFESSORANALYSIS_NAME);
	SQLPARAMS_UPDATE_STRING(PROFESSOR_GRADES);
	SQLPARAMS_UPDATE_STRING(PROFESSOR_DATE);
	SQLPARAMS_UPDATE_STRING(PROFESSIONAL_CATEGORY);
	SQLPARAMS_UPDATE_STRING(issuing_authority);
	SQLPARAMS_UPDATE_STRING(judging_unit);
	SQLPARAMS_UPDATE_PUSH_FINAL(b_highest_professional_title, "%b", id);
	return sqlSession->executeUpdate(sql.str(), fmts.str().c_str(),
		uObj.getName(),
		uObj.getUpdateman(),
		uObj.getCreatedate(),
		uObj.getCreateman(),
		uObj.getUpdatedate(),
		uObj.getFylb(),
		uObj.getFyje(),
		uObj.getFfrs(),
		uObj.getFfsj(),
		uObj.getFybz(),
		uObj.getBz(),
		uObj.getId());
}
