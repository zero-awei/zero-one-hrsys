#pragma once
/*
证书管理-分页查询证书列表--pine
*/
#ifndef _CHECK_CER_LIST_SERVICE_
#define _CHECK_CER_LIST_SERVICE_
#include <list>
#include "domain/query/CertificateManage/CheckCerListQuery.h"
#include "domain/dto/CertificateManage/CheckCerListDTO.h"
#include "domain/vo/CertificateManage/CheckCerListVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CheckCerListService
{
public:
	// 分页查询所有数据
	CheckCerListPageDTO::Wrapper listAll(const CheckCerListQuery::Wrapper& query);

};

#endif // !_CHECK_CER_LIST_SERVICE_

