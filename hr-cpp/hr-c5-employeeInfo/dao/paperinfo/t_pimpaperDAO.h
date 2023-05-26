#pragma once

#ifndef _T_PIMPAPER_DAO_
#define _T_PIMPAPER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/paperinfo/t_pimpaperDO.h"
#include "../../domain/query/paperinfo/PaperQuery.h"

/**
 * ������Ϣ�����ݿ����ʵ��
 */
class t_pimpaperDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PaperQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<t_pimpaperDO> selectWithPage(const PaperQuery::Wrapper& query);
	// �޸�����
	int update(const t_pimpaperDO& uObj);
};
#endif