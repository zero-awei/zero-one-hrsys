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
#include "OrgSectorDAO.h"
#include "OrgSectorMapper.h"
#include <sstream>

list<OrgSectorDO> OrgSectorDAO::selectOrgSector(const SectorQuery::Wrapper &query) {
    stringstream sql;
    sql << "SELECT ORGSECTORID, ORGSECTORNAME, ORGID, ORGNAME\
            FROM t_orgsector\
            WHERE ";
    if (query->parentdename.getValue("") == "OrmOrg") {
        sql << "ORGID = ?";
    } else if (query->parentdename.getValue("") == "OrmOrgsector") {
        sql << "PORGSECTORID = ?";
    }
    OrgSectorMapper mapper;
    return sqlSession->executeQuery<OrgSectorDO, OrgSectorMapper>(sql.str(), mapper, "%s", query->parentkey.getValue(""));
}