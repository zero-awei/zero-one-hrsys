#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_SERVICE_
#define _DELETE_LEGAL_ENTITY_SERVICE_
#include <list>
#include "domain/query/LegalEntitySet/DeleteLegalEntityQuery.h"
#include "domain/dto/LegalEntitySet/DeleteLegalEntityDTO.h"
#include "domain/vo/LegalEntitySet/DeleteLegalEntityVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DeleteLegalEntityService
{
public:
public:
	// 通过ID删除数据
	bool removeData(const DeleteLegalEntityDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

