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


int EmployeeInfoDAO::updateEmployee(const EmployeeInfoDTO::Wrapper& edto)
{
	stringstream sql;
	sql << "UPDATE `t_pimperson` SET `YGBH`=?,`PIMPERSONNAME`=?,`ZJLX`=?,";
	sql << "`ZJHM`=?,`CSRQ`=?,`NL`=?,`XB`=?,`XX`=?,`LXDH`=?,`DZYX`=?,`HYZK`=?,";
	sql << "`MZ`=?,`HKLX`=?,`JG`=?,`HJSZD`=?,`HJDZ`=?,`CSD`=?,`POSTALADDRESS`=?,";
	sql << "`SFDSZN`=?,`AHTC`=?,`JKZK`=?,`ZZMM`=?,`YGZT`=?,`WORKSTATE=?`,";
	sql << "`RZQD`=?,`CJGZSJ`=?,`DBDWSJ`=?,`HMD`=?,`ZP`=? WHERE `PIMPERSONID`=?";
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s"
		, edto->empid, edto->name,edto->idtype,edto->idnum,edto->bthdate,edto->age, edto->sex, edto->blood,
		edto->phone, edto->email,edto->marriage, edto->nation, edto->residentType, edto->native, edto->residentPlace,
		edto->residentLocate, edto->birthPlace, edto->comPlace, edto->onlyCredit, edto->hobby, edto->health,
		edto->politic, edto->state, edto->workstate, edto->inway, edto->workTime, edto->inTime, edto->blacklist,
		edto->photo,edto->pimpersonid);
}

int EmployeeInfoDAO::insertEmployee(const EmployeeInfoAddDTO::Wrapper& eadto,string pimid,string dt)
{
	stringstream sql;
	sql << "INSERT INTO `t_pimperson` (`PIMPERSONID`,`YGBH`,`PIMPERSONNAME`,`ZJLX`,";
	sql << "`ZJHM`,`LXDH`,`YGZT`,`UPDATEDATE`,`CREATEDATE`) VALUE(?,?,?,?,?,?,?)";//,`CREATEMAN`,`UPDATEMAN`
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%s%s%s%s%s%s", pimid, eadto->empid,
		eadto->name, eadto->idType, eadto->idNum, eadto->phoneNum, eadto->state,dt,dt);
}

std::list<EmployeeInfoDO> EmployeeInfoDAO::selectEmployee(const EmployeeInfoQuery::Wrapper& query)
{
	stringstream sql;
	SqlParams par;
	sql << "SELECT `YGBH`,`PIMPERSONNAME`,`ZJLX`,`ZJHM`,`CSRQ`,`NL`,`XB`,";
	sql << "`MZ`,`JG`,`HYZK`,`ZZMM`,`RANK`,`CJGZSJ`,`DBDWSJ`,`DZYX`,`HIGHTITLE`,";
	sql<< "`HIGHEDUCATION`,`FIRSTEDUCATION`,`CRERRIFICATE`,`ZP`,`LXDH` ";
	sql<<"FROM t_pimperson WHERE 1 = 1";
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
