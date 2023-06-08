#include "stdafx.h"
#include "CertificateInformationDAO.h"
#include "CertificateInformationMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<"WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}
//统计证书的记录数
uint64_t CertificateInformationDAO::count(const CertificateInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimvocational`  ";
	CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//证书分页查询函数
list<CertificateInformationDO> CertificateInformationDAO::selectWithPage(const CertificateInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT zgzsbh,pimvocationalname,b.name,zghqrq,zgsydw,fzyxq,pimpersonid FROM t_pimvocational left join zo_credentialtype b  on   zslx=b.code ";
	CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CertificateInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateInformationDO, CertificateInformationMapper>(sqlStr, mapper, params);
}