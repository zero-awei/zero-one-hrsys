#include "stdafx.h"
#include "ContractInfoDAO.h"
#include "../Gosh/GoshMapper.h"
#include <sstream>


std::list<ContractDO> ContractInfoDAO::selectById(const string& id)
{
	string sql = "SELECT * FROM test WHERE `id` LIKE CONCAT('%',?,'%')";
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%s", id);
}

int ContractInfoDAO::update(const ContractDO& uObj)
{
	string sql = "UPDATE `test` SET `name`=?,`type`=?, `variety`=?,`date`=?,`condition`=?,`department_m`=?,`department_c`=?,`date_end`=?,`tip`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%ull", uObj.getName(),uObj.getType(), uObj.getVariety(), uObj.getDate(), \
		uObj.getCondition(), uObj.getDepartment_m(), uObj.getDepartment_c(), uObj.getDate_end(), uObj.getTip(), uObj.getId());
}


std::list<ContractDO> ContractInfoDAO::downloadByRows(oatpp::String sequence, UInt64 rows)
{
	string sql;
	if(sequence == "DESC")
	{
		sql = "SELECT * FROM `test` ORDER BY `id` DESC LIMIT ?";
	}
	else
	{
		sql = "SELECT * FROM `test` ORDER BY `id` LIMIT ?";
	}
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%ull", rows);

}



uint64_t ContractInfoDAO::insert(const ContractDO& iObj)
{
	string sql = "INSERT INTO `test` (`id`, `name`, `type`, `variety`,`date`,`condition`,`department_m`,`department_c`,`date_end`,`tip`) VALUES (?, ?, ?, ?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%ull%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getName(), iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(), iObj.getDepartment_c(), iObj.getDate_end(), iObj.getTip());
}