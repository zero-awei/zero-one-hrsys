#ifndef _Gosh_SERVICE_
#define _Gosh_SERVICE_
#include <list>
#include "domain/vo/Gosh/ContractVO.h"
#include "domain/query/Gosh/ContractQuery.h"
#include "domain/query/Gosh/PersonQuery.h"
#include "domain/dto/Gosh/ContractDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GoshService
{
public:
	// 分页查询所有数据
	ContractDTO_gs::Wrapper listAll(const ContractQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ContractDTO_gs::Wrapper& dto);
	// 修改数据
	bool updateData(const ContractDTO_gs::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
