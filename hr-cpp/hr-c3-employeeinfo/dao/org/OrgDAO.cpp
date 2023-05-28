/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
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
#include "OrgDAO.h"
#include "OrgMapper.h"
#include <sstream>

list<OrgDO> OrgDAO::selectRootOrg(const RootOrgQuery::Wrapper &query, string userId) {
    // 先不做sort
    stringstream sql;
    sql << "SELECT tmp.COMPANYFLAG, tmp.ORGID, tmp.ORGNAME, tmp.PORGID, t_org.PORGNAME\
            FROM t_org INNER JOIN\
            (SELECT COMPANYFLAG, ORGID, ORGNAME, PORGID \
            FROM t_org\
            WHERE CREATE_MAN = ?) tmp\
            ON t_org.ORGID = tmp.PORGID\
            ORDER BY tmp.ORGID\
            LIMIT ?, ?;";

    string sqlStr = sql.str();
    OrgMapper mapper;
    uint64_t start = (query->pageIndex - 1) * query->pageSize;
    uint64_t num = query->pageSize;
    return sqlSession->executeQuery<OrgDO, OrgMapper>(sqlStr, mapper, "%s%ull%ull", userId, start, num);
}

list<OrgDO> OrgDAO::selectValidOrg(const ValidOrgQuery::Wrapper &query) {
    // 先不做sort
    stringstream sql;
    sql << "SELECT tmp.COMPANYFLAG, tmp.ORGID, tmp.ORGNAME, tmp.PORGID, t_org.PORGNAME\
            FROM t_org INNER JOIN\
            (SELECT COMPANYFLAG, ORGID, ORGNAME, PORGID \
            FROM t_org\
            WHERE PORGID = ?) tmp\
            ON t_org.ORGID = tmp.PORGID\
            ORDER BY tmp.ORGID\
            LIMIT ?, ?;";

    string sqlStr = sql.str();
    OrgMapper mapper;
    uint64_t start = (query->pageIndex - 1) * query->pageSize;
    uint64_t num = query->pageSize;
    return sqlSession->executeQuery<OrgDO, OrgMapper>(sqlStr, mapper, "%s%ull%ull", query->porgid.getValue(""), start, num);
}