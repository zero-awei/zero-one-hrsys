#pragma once
#ifndef _J_PAPERINFO_DAO_
#define _J_PAPERINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/J_paperinfo/J_paperinfoDO.h"

/**
 * 论文表数据库操作实现
 */
class PaperinfoDAO : public BaseDAO
{
public:

	// 通过论文信息编码查询数据
	list<J_PaperinfoDO> selectBypimpaperid(const string& st);
	// 修改数据
	int update(const J_PaperinfoDO& uObj);

};
#endif // !_PAPERINFO_DAO_