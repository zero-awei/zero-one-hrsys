
#include "stdafx.h"
#include "JobTitleDAO.h"
#include "JobTitleMapper.h"
#include "SqlSession.h"
#include "JobTitleDAO.h"
#include <sstream>
#include <domain/dto/JobTitle/JobTitleDTO.h>

#define SAMPLE_QUERY_PARSE(query, sql) \
SqlParams params; \
if (query->param) { \
	sql << "and tpp.YGBH like concat('%',?,'%') ";\
    SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));\
	sql << "or tpp.PIMPERSONNAME like concat('%',?,'%')";\
	SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));\
}

uint64_t JobTitleDAO::count(const JobTitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select count(*) from t_pimtitle as tpt LEFT JOIN t_pimperson as tpp on tpt.PIMPERSONID = tpp.PIMPERSONID LEFT JOIN t_pimtitlecatalogue as tpc ON ";
	sql << "tpt.PIMTITLEID = tpc.PIMTITLEID LEFT JOIN bis_titlegrade_t as btt on tpt.ZCDJ = btt.TITLEGRADEVALUE LEFT JOIN bis_professoranalysis_t as bpt ON bpt.EMPLOYEEID = tpt.EMPLOYTIME ";
	sql << "LEFT JOIN t_personstatemgr  as tpr ON tpr.PERSONSTATECODE = tpp.YGZT LEFT JOIN t_pimtitlecatalogue as tpg ON tpg.PIMTITLECATALOGUEID = tpt.PIMTITLECATALOGUEID ";
	//sql << "where tpp.YGBH is not NULL and tpg.PIMTITLECATALOGUENAME is not NULL ";
	// 查看是否有参数，如果有带上参数查询
	SqlParams params;
	if (query->param) {
		cout << "携带参数:" << query->param.getValue("") << endl;
		sql << "where 1=1 and tpp.YGBH like concat('%',?,'%') ";
		SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));
		sql << "or tpp.PIMPERSONNAME like concat('%',?,'%')";
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
	sql << "select tpt.PIMTITLEID as '职称信息标识',tpp.YGBH as '员工编号',tpp.PIMPERSONNAME as '员工姓名',tpr.PERSONSTATEMGRNAME as '员工状态',tpp.ORMORGNAME as '组织',";
	sql << "tpg.PIMTITLECATALOGUENAME as '职称名称',tpt.ZCHQRQ as '职称获取日期',tpt.ZCBH as '证书编号',tpt.MAJORENGAGED as '专业类别',";
	sql << "btt.TITLEGRADENAME as '职称等级', tpt.EMPLOYTIME as '职称聘用时间', tpt.LSSUINGAGENCY as '签发机构', tpt.REVIEWBODY as '评审单位', tpp.HIGHTITLE as '最高职称'";
	sql << "from t_pimtitle as tpt LEFT JOIN t_pimperson as tpp on tpt.PIMPERSONID = tpp.PIMPERSONID LEFT JOIN t_pimtitlecatalogue as tpc ON ";
	sql << "tpt.PIMTITLEID = tpc.PIMTITLEID LEFT JOIN bis_titlegrade_t as btt on tpt.ZCDJ = btt.TITLEGRADEVALUE LEFT JOIN bis_professoranalysis_t as bpt ON bpt.EMPLOYEEID = tpt.EMPLOYTIME ";
	sql << "LEFT JOIN t_personstatemgr  as tpr ON tpr.PERSONSTATECODE = tpp.YGZT LEFT JOIN t_pimtitlecatalogue as tpg ON tpg.PIMTITLECATALOGUEID = tpt.PIMTITLECATALOGUEID ";
	//sql << "where tpp.YGBH is not NULL and tpg.PIMTITLECATALOGUENAME is not NULL ";
	sql << "where 1=1 ";
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
	string sql = "insert into `t_pimtitle` (`CREATEDATE`,`PIMTITLEID`,`PIMTITLENAME`,`ZCHQRQ`,`ZCBH`,`ZCDJ`,`MAJORENGAGED`,`CAREERNAME`,";
	sql += "`LSSUINGAGENCY`,`REVIEWBODY`,`EMPLOYTIME`) VALUES(NOW(),?,?,?,?,?,?,?,?,?,?)";
	// 附加参数
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", string, aObj.getId());
	//SQLPARAMS_PUSH(params, "s", string, aObj.getEmployee_Id());
	//SQLPARAMS_PUSH(params, "s", string, aObj.getEmployee_Name());
	SQLPARAMS_PUSH(params, "s", string, aObj.getJobtitle_Name());
	SQLPARAMS_PUSH(params, "s", string, aObj.getGet_Time());
	//SQLPARAMS_PUSH(params, "s", string, aObj.getEmployee_State());
	//SQLPARAMS_PUSH(params, "s", string, aObj.getOrg_Name());
	SQLPARAMS_PUSH(params, "s", string, aObj.getCertificate_Id());
	SQLPARAMS_PUSH(params, "s", string, aObj.getJobtitle_Grades());
	SQLPARAMS_PUSH(params, "s", string, aObj.getProfessional_Cate());
	SQLPARAMS_PUSH(params, "s", string, aObj.getTitle_Employment_Time());
	SQLPARAMS_PUSH(params, "s", string, aObj.getIssuing_Authority());
	SQLPARAMS_PUSH(params, "s", string, aObj.getJudging_Unit());
	SQLPARAMS_PUSH(params, "s", string, aObj.getTitle_Employment_Time());
	//SQLPARAMS_PUSH(params, "s", string, aObj.getB_Highest_Professional_Title());
	cout << "employee_name:" << aObj.getEmployee_Name() << endl;
	return sqlSession->executeUpdate(sql, params);
}

// 支持批量删除
uint64_t JobTitleDAO::removeById(const JobTitleDeleteDTO::Wrapper& list)
{
	// 创建批量删除sql,拼接sql
	stringstream sql;
	sql << "delete from `t_pimtitle` where PIMTITLEID in (";
	SqlParams params;
	auto it = list->list_jobtitle_id->begin();
	while (it != list->list_jobtitle_id->end()) {
		//sql << "concat(''', ? , ''')";    // 拼接单引号
		sql << "?";
		SQLPARAMS_PUSH(params, "s", string, (*it).getValue(""));
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


