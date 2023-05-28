#pragma once
#ifndef _CONTRACTSERVICE_H_
#define _CONTRACTSERVICE_H_
#include <list>
#include "domain/vo/contractType/ContractTypeVO.h"
#include "domain/query/contractType/ContractTypeQuery.h"
#include "domain/dto/contractType/ContractTypeDTO.h"

class ContractService
{
public:
	// 分页查询所有数据
	ContractTypePageDTO::Wrapper listAll(const ContractTypeQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ContractTypeDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ContractTypeDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_CONTRACTSERVICE_H_