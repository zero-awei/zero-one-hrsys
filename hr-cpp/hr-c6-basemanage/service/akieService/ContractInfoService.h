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
	// 下载合同
	std::string downloadContract(const ContractDownloadQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ContractDTO_::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_