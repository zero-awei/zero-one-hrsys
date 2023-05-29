/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
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

