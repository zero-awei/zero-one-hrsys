/*
（人员花名册-人员花名册-分页查询员工数据）--洛洛
*/
#include "stdafx.h"
#include "EmployeePageDAO.h"
#include "EmployeePageMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define EMPLOYEEPAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->idAndName) { \
	sql << " AND `YGBH`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idAndName.getValue("")); \
} \
if (query->idAndName) { \
	sql << " OR `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idAndName.getValue("")); \
} \

uint64_t EmployeePageDAO::count(const EmployeePageQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pcmdetail";
	EMPLOYEEPAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<RosterPersonDO> EmployeePageDAO::selectWithPage(const EmployeePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `PCMDETAILID`, `PCMDETAILNAME`, `CREATEMAN`,  `CREATEDATE`, `UPDATEMAN`, \
`UPDATEDATE`, `ORMORGID`, `YGBH`, `XB`, `MZ`, `ZJHM`, `JG`, `HYZK`, `CSRQ`,  `ZZMM`, `RDSJ`, \
`ORMORGNAME`, `GW`, `PIMMAJORSETYPENAME`, `ORMORGSECTORID`, `PIMPERSONNAME`, `HJDZ`, `HKXZ`, \
`ZW`, `CAREERNAME`, `GWTYPE`, `PIMVOCATIONALCATALOGNAME`, `PIMQUALTYPENAME`, `SBCJD`, `FIRSTEDUCATION`, \
`DYXLBYYX`, `DYXLSXZY`,  `XXLB`, `SFZGXL`,  `ZGXLBYYX`, `ZGXLSXZY`, `ZGXLJSSJ`, \
`CONTRACTTYPE`, `QSRQ`, `JSRQ`, `HTQX`, `HTSYQ`, `RZQD`, `LXDH`, `YGLX`, `JXKHCJ`, `BZ`, `ZCBH`, `KSTGKMS`, \
`PX`, `SFZCKJS`, `TOZJDATE`, `GZNX`, `ZJXTGZNX`, `BJGZNX`, `DZJBJSJ`, `DBDWSJ`,  `ZGZSBH`, `CJGZSJ`, \
`FIELD`, `ZGXXLB`, `ZGXLLX`, `DYXL`, `ZGXL`, `HTLB` FROM t_pcmdetail ";
	EMPLOYEEPAGE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EmployeePageMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RosterPersonDO, EmployeePageMapper>(sqlStr, mapper, params);
}

