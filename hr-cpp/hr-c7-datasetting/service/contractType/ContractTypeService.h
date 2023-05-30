#pragma once
#ifndef _CONTRACTSERVICE_H_
#define _CONTRACTSERVICE_H_
#include <list>
#include "domain/vo/contractType/ContractTypeVO.h"
#include "domain/query/contractType/ContractTypeQuery.h"
#include "domain/dto/contractType/ContractTypeDTO.h"

class ContractTypeService
{
public:
	// ��ҳ��ѯ��������
	ContractTypePageDTO::Wrapper listAll(const ContractTypeQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ContractTypeDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ContractTypeDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_CONTRACTSERVICE_H_