#pragma once
#ifndef _PAPERINFO_DAO_
#define _PAPERINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/query//paperinfo/PaperQuery.h"
#include "../../domain/do/paperinfo/paperinfo.h"

/**
 * 论文表数据库操作实现
 */
class PaperinfoDAO : public BaseDAO
{
public:

	// 通过论文信息编码查询数据
	list<PaperinfoDO> selectBypimpaperid(const string& st);
	// 修改数据
	int update(const PaperinfoDO& uObj);

};
#endif // !_PAPERINFO_DAO_