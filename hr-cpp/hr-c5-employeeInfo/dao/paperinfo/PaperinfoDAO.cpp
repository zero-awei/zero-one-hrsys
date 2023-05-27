#include "stdafx.h"
#include "PaperinfoDAO.h"
#include "PaperinfoMapper.h"
#include <sstream>



// 查看指定员工论文信息（指定论文信息详情）
std::list<t_pimpaperDO> PaperinfoDAO::selectBypimpaperid(const PaperQuery::Wrapper& query)
{


	stringstream sql;
	sql << "SELECT * FROM t_pimpaper";
	SqlParams params;
	sql << " WHERE 1=1";
	sql << " AND `pimpaperid` LIKE CONCAT('%',?,'%')";
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpaper.getValue(""));
	PaperinfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<t_pimpaperDO, PaperMapper>(sqlStr, mapper, params);



}


// 修改数据
int PaperinfoDAO::update(const t_pimpaperDO& uObj)
{
	string sql = "UPDATE `t_pimpaper` SET `grzlwzzzdpm`=?, `updateman`=?, `createdate`=?, `updatedate`=?,\
											 `createman`=?, `fbsj`=?, `pimpapername`=?, `cbshkwmc`=?,\
											 `pimpersonid`=?, `fj`=?, `jlspzt`=?, `jlglbh`=?,\
											 `jlczz`=?, `jlss`=?, `cbs`=?, `kwmc`=?, \
												`kwqs`=?, `reason`=? WHERE `pimpaperid`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		uObj.getGRZLWZZZDPM(),
		uObj.getUPDATEMAN(),
		uObj.getCREATEDATE(),
		uObj.getUPDATEDATE(),
		uObj.getCREATEMAN(),
		uObj.getFBSJ(),
		uObj.getPIMPAPERNAME(),
		uObj.getCBSHKWMC(),
		uObj.getPIMPERSONID(),
		uObj.getFJ(),
		uObj.getJLSPZT(),
		uObj.getJLGLBH(),
		uObj.getJLCZZ(),
		uObj.getJLSS(),
		uObj.getCBS(),
		uObj.getKWMC(),
		uObj.getKWQS(),
		uObj.getREASON(),
		uObj.getPIMPAPERID());
}

