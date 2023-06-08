/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityService.h"
#include "../../dao/LegalEntitySet/DeleteLegalEntityDAO.h"

bool DeleteLegalEntityService::removeData(const DeleteLegalEntityDTO::Wrapper& dto)
{
	DeleteLegalEntityDAO dao;
	for (auto it = dto->contractsignorgid->begin(); it != dto->contractsignorgid->end(); ++it)
	{
		//*it是String类型的对象，deleteById需要的是string的参数传入
		dao.update((*it).getValue(""));
		dao.deleteById((*it).getValue(""));
	}
	return true;
}


