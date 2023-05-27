#pragma once

#ifndef _Contract_Info_SERVICE_
#define _Contract_Info_SERVICE_
#include <list>
#include "domain/vo/ContractVO/ContractVO_.h"
#include "domain/query/ContractQuery/ContractQuery_.h"
#include "domain/dto/ContractDTO/ContractDTO_.h"

/**
 * akie实现service
 */
class ContractInfoService
{
public:
	// 查看指定合同信息
	ContractDTO_::Wrapper listContract(const ContractQuery_::Wrapper& query);
	// 修改指定合同
	bool updateContract(const ContractDTO_::Wrapper& dto);
	// 修改数据
	//bool updateData(const ContractDTO_::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_