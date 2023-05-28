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
	string sql = "SELECT * FROM test ORDER BY id ? LIMIT ?";
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%s%ull", sequence, rows);

}