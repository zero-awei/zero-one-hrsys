#pragma once
/*
（证书管理-证书信息-删除证书）--洛洛
*/
#ifndef _DELETECERTIF_DAO_
#define _DELETECERTIF_DAO_
#include "BaseDAO.h"

class DeleteCertifDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_DELETECERTIF_DAO_
