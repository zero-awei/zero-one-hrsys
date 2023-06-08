/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/25 8:20:18

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
#include"stdafx.h"
#include"EmployeeInfoDAO.h"
#include"EmployeeInfoMapper.h"


int EmployeeInfoDAO::updateEmployee(const EmployeeInfoDTO::Wrapper& edto, string pl)
{
	stringstream sql;
	sql << "UPDATE `t_pimperson` SET `YGBH`=?,`PIMPERSONNAME`=?,`ZJLX`=?,";
	sql << "`ZJHM`=?,`CSRQ`=?,`NL`=?,`XB`=?,`XX`=?,`LXDH`=?,`DZYX`=?,`HYZK`=?,";
	sql << "`MZ`=?,`HKLX`=?,`JG`=?,`HJSZD`=?,`HJDZ`=?,`CSD`=?,`POSTALADDRESS`=?,";
	sql << "`SFDSZN`=?,`AHTC`=?,`JKZK`=?,`ZZMM`=?,`YGZT`=?,`WORKSTATE`=?,";
	sql << "`RZQD`=?,`CJGZSJ`=?,`DBDWSJ`=?,`HMD`=?,`ZP`=?,`UPDATEMAN`=? WHERE `PIMPERSONID`=?";
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s"
		, edto->empid.getValue({}), edto->name.getValue({}), edto->idtype.getValue({}), edto->idnum.getValue({}),
		edto->bthdate.getValue({}), edto->age.getValue({}), edto->sex.getValue({}), edto->blood.getValue({}),
		edto->phone.getValue({}), edto->email.getValue({}), edto->marriage.getValue({}), edto->nation.getValue({}),
		edto->residentType.getValue({}), edto->native.getValue({}), edto->residentPlace.getValue({}),
		edto->residentLocate.getValue({}), edto->birthPlace.getValue({}), edto->comPlace.getValue({}),
		edto->onlyCredit.getValue({}), edto->hobby.getValue({}), edto->health.getValue({}),
		edto->politic.getValue({}), edto->state.getValue({}), edto->workstate.getValue({}), edto->inway.getValue({}),
		edto->workTime.getValue({}), edto->inTime.getValue({}), edto->blacklist.getValue({}),
		edto->photo.getValue({}), edto->pimpersonid.getValue({}), pl);
}

int EmployeeInfoDAO::insertEmployee(const EmployeeInfoAddDTO::Wrapper& eadto, string pimid, string dt, string pl)
{
	stringstream sql;
	sql << "INSERT INTO `t_pimperson` (`PIMPERSONID`,`YGBH`,`PIMPERSONNAME`,`ZJLX`,";
	sql << "`ZJHM`,`LXDH`,`YGZT`,`UPDATEDATE`,`CREATEDATE`,`CREATEMAN`,`UPDATEMAN`) VALUE(?,?,?,?,?,?,?,?,?,?,?)";//,
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%s%s%s%s", pimid, eadto->empid.getValue({}),
		eadto->name.getValue({}), eadto->idType.getValue({}), eadto->idNum.getValue({}),
		eadto->phoneNum.getValue({}), eadto->state.getValue({}), dt, dt, pl, pl);
}

std::list<EmployeeInfoDO> EmployeeInfoDAO::selectEmployee(const EmployeeInfoQuery::Wrapper& query)
{
	stringstream sql;
	SqlParams par;
	sql << "SELECT `YGBH`,`PIMPERSONNAME`,`ZJLX`,`ZJHM`,`CSRQ`,`NL`,`XB`,";
	sql << "`MZ`,`JG`,`HYZK`,`ZZMM`,`RANK`,`CJGZSJ`,`DBDWSJ`,`DZYX`,`HIGHTITLE`,";
	sql << "`HIGHEDUCATION`,`FIRSTEDUCATION`,`CERTTIFICATE`,`ZP`,`LXDH` ";
	sql << "FROM t_pimperson WHERE 1 = 1";
	if (query->pimpersonid)
	{
		sql << " AND PIMPERSONID=?";
		SQLPARAMS_PUSH(par, "s", std::string, query->pimpersonid.getValue(""));
	}
	if (query->id) {
		sql << " AND YGBH=?";
		SQLPARAMS_PUSH(par, "s", std::string, query->id.getValue(""));
	}
	if (query->name) {
		sql << " AND PIMPERSONNAME=?";
		SQLPARAMS_PUSH(par, "s", std::string, query->name.getValue(""));
	}
	EmployeeInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EmployeeInfoDO, EmployeeInfoMapper>(sqlStr, mapper, par);
}
