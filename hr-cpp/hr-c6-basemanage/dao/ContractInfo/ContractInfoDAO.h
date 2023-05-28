#pragma once
#ifndef _Contract_Info_DAO_
#define _Contract_Info_DAO_
#include "BaseDAO.h"
#include "domain/do/Gosh/ContractDO.h"
#include "domain/query/Gosh/ContractQuery.h"

/**
 * 示例表数据库操作实现
 */
class ContractInfoDAO : public BaseDAO
{
public:
	// 通过ID查询合同信息
	list<ContractDO> selectById(const string& Id);

	//更新指定合同
	int update(const ContractDO& uObj);

	//按rows导出数据
	std::list<ContractDO> downloadByRows(oatpp::String sequence, UInt64 rows);

	// 插入数据
	uint64_t insert(const ContractDO& iObj);
};
#endif // !_SAMPLE_DAO_