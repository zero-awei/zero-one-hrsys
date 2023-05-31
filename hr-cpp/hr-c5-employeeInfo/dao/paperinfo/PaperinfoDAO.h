#pragma once
#ifndef _PAPERINFO_DAO_
#define _PAPERINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/query//paperinfo/PaperQuery.h"
#include "../../domain/do/paperinfo/t_pimpaperDO.h"

/**
 * 论文表数据库操作实现
 */
class PaperinfoDAO : public BaseDAO
{
public:

	// 通过论文信息编码查询数据
	list<t_pimpaperDO> selectBypimpaperid(const string& st);
	// 修改数据
	int update(const t_pimpaperDO& uObj);

};
#endif // !_PAPERINFO_DAO_