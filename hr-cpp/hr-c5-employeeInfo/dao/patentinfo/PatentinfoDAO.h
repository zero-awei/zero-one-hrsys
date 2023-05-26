#pragma once
#ifndef _PATENTINFO_DAO_
#define _PATENTINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/patentinfo/t_pimpatentDO.h"
#include "../../domain/query/patentinfo/PatentinfoQuery.h"

/**
 * 专利表数据库操作实现
 */
class PatentinfoDAO : public BaseDAO
{
public:


	// 通过专利信息编码查询数据
	list<PatentinfoDO> selectByPIMPATENTID(const PatentinfoQuery::Wrapper& query);

	//list<PatentinfoDO> selectByPIMPATENTID(const string& PIMPATENTID);

	// 修改数据
	//int update(const PatentinfoDO& uObj);

};
#endif // !_SAMPLE_DAO_