#include "stdafx.h"
#include "CertificateInformationDAO.h"
#include "CertificateInformationMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ygbh) { \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ygbh.getValue("")); \
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
	sql << "SELECT a.zgzsbh,a.pimvocationalname,b.name,a.zghqrq,a.zgsydw,a.fzyxq FROM t_pimvocational a,zo_credentialtype b where a.zslx=b.code  ";
	CERTIFACATE_INFORMATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CertificateInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateInformationDO, CertificateInformationMapper>(sqlStr, mapper, params);
}