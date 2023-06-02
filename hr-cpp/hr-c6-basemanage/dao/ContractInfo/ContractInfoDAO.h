#pragma once
#ifndef _Contract_Info_DAO_
#define _Contract_Info_DAO_
#include "BaseDAO.h"
#include "domain/do/contractInfoakie/ContractInfoDO.h"
#include "domain/query/ContractQuery/ContractQuery_.h"

/**
 * 示例表数据库操作实现
 */
class ContractInfoDAO : public BaseDAO
{
public:
	// 通过id查询合同信息
	list<ContractInfoDO> selectByInfoid(const string& infoid);

	//更新指定合同
	int update(const ContractInfoDO& uObj);

	//按rows导出数据
	std::list<ContractInfoDO> downloadByFiltration(const ContractDownloadQuery::Wrapper& query);

	// 插入数据
	uint64_t insert(const ContractInfoDO& iObj);
};
#endif // !_SAMPLE_DAO_