#pragma once
#ifndef _J_PATENTINFO_DAO_
#define _J_PATENTINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/J_patentinfo/J_t_pimpatentDO.h"

/**
 * 专利表数据库操作实现
 */
class PatentinfoDAO : public BaseDAO
{
public:


	// 通过专利信息编码查询数据
	list<J_PatentinfoDO> selectByPIMPATENTID(const string& pimpatentid);
	// 修改数据
	int update(const J_PatentinfoDO& uObj);

};
#endif // !_PATENTINFO_DAO_