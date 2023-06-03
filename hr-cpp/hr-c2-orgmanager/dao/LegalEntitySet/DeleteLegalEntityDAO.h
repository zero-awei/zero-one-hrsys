#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_DAO_
#define _DELETE_LEGAL_ENTITY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "../../domain/query/LegalEntitySet/DeleteLegalEntityQuery.h"


class DeleteLegalEntityDAO : public BaseDAO
{
public:
	//更新子表的外键为空
	int update1(string id);
	int update2(string id);
	int update3(string id);
	// 通过ID删除数据  
	int deleteById(string id);

};
#endif // !_SAMPLE_DAO_
