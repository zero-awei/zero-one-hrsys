#pragma once


#ifndef _PIMARMYCADRESDAO_H_
#define _PIMARMYCADRESDAO_H_

#include "BaseDAO.h"
#include "domain/query/Pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/do/Pimarmycadres/PimarmycadresFindDO.h"


#include "../../domain/do/Pimarmycadres/AddPimarmycadresDO.h"
#include "../../domain/query/Pimarmycadres/PimarmycadresQuery.h"
#include "../../domain/do/Pimarmycadres/PimarmycadresDO.h"

class PimarmycadresDAO : public BaseDAO
{
public:
	// 分页查询数据
	list<PimarmycadresFindDO> selectWithPage(const PimarmycadresPageQuery::Wrapper& query);

	//插入数据
	uint64_t insert(const AddPimarmycadresDO& iObj);

	// 统计数据条数
	uint64_t count(const PimarmycadresPageQuery::Wrapper& query);
	
	//查询数据，把查询的数据填入Excel中  (导出？？）
	list<PimarmycadresFindDO> selectDetail(const PimarmycadresQuery::Wrapper& query);
	

	int update(const PimarmycadresDO& uObj);

	//删除数据（支持批量删除数据）
	int deleteById(std::string pimpersonid, std::string pimarmycadresid);

};



#endif
