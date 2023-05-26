#pragma once

#ifndef _T_PIMPAPER_DAO_
#define _T_PIMPAPER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/paperinfo/t_pimpaperDO.h"
#include "../../domain/query/paperinfo/PaperQuery.h"

/**
 * 论文信息表数据库操作实现
 */
class t_pimpaperDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const t_pimpaperDO& iObj);
	// 统计数据条数
	uint64_t count(const PaperQuery::Wrapper& query);
	// 分页查询数据
	list<t_pimpaperDO> selectWithPage(const PaperQuery::Wrapper& query);
};
#endif
