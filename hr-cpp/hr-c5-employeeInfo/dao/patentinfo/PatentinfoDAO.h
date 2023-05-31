#pragma once
#ifndef _PATENTINFO_DAO_
#define _PATENTINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/patentinfo/t_pimpatentDO.h"
#include "../../domain/query/patentinfo/PatentinfoQuery.h"

/**
 * ר�������ݿ����ʵ��
 */
class PatentinfoDAO : public BaseDAO
{
public:


	// ͨ��ר����Ϣ�����ѯ����
	list<PatentinfoDO> selectByPIMPATENTID(const string& pimpatentid);
	// �޸�����
	int update(const PatentinfoDO& uObj);

};
#endif // !_PATENTINFO_DAO_