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
#include <sstream>

list<OrgTreeDO> OrgDAO::selectRootOrg(const string &userId)
{
    // 先不做sort
    stringstream sql;
    sql << "SELECT \"company\", ORGID, ORGNAME, PORGID \
            FROM t_org\
            WHERE CREATEMAN = ?";

    string sqlStr = sql.str();
    OrgTreeMapper mapper;
    return sqlSession->executeQuery<OrgTreeDO, OrgTreeMapper>(sqlStr, mapper, "%s", userId);
}

list<OrgTreeDO> OrgDAO::selectValidOrg(const string &parentId)
{
    // 先不做sort
    stringstream sql;
    sql << "SELECT \"company\", ORGID, ORGNAME, PORGID \
            FROM t_org\
            WHERE PORGID = ? && PORGID != ORGID;";

    string sqlStr = sql.str();
    OrgTreeMapper mapper;
    return sqlSession->executeQuery<OrgTreeDO, OrgTreeMapper>(sqlStr, mapper, "%s", parentId);
}

list<OrgTreeDO> OrgDAO::selectOrgSector(const string &parentId)
{
    // 先不做sort
    stringstream sql;
    sql << "SELECT \"sector\", ORGSECTORID, ORGSECTORNAME, ORGID \
            FROM t_orgsector\
            WHERE ORGID = ?;";

    string sqlStr = sql.str();
    OrgTreeMapper mapper;
    return sqlSession->executeQuery<OrgTreeDO, OrgTreeMapper>(sqlStr, mapper, "%s", parentId);
}