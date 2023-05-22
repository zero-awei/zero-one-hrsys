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
	// ∑÷“≥’π æ
	ContractTypePageDTO::Wrapper listAll(const ContractTypeQuery::Wrapper& query);
};

#endif // !_CONTRACTSERVICE_H_