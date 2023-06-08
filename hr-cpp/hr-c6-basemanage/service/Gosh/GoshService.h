#pragma once
#ifndef _Gosh_SERVICE_
#define _Gosh_SERVICE_
#include <list>
#include "domain/vo/Gosh/ContractVO.h"
#include "domain/query/Gosh/ContractQuery.h"
#include "domain/dto/Gosh/ContractDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GoshService
{
public:
	// 分页查询合同数据
	ContractPageDTO_gs::Wrapper listContract(const ContractQuery::Wrapper& query);
	//分页查询员工数据
	ContractPageDTO_gs::Wrapper listPerson(const ContractQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ContractDTO_gs_insert::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const ContractDTO_gs_delete::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_