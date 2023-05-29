#include "stdafx.h"
#include "AuditStatusDAO.h"
#include "AuditStatusMapper.h"

std::list<AuditStatusDO> AuditStatusDAO::listAll()
{
	list<AuditStatusDO> res;
	for (auto item : auditStatus)
	{
		AuditStatusDO tmp(item.first, item.second);
		res.push_back(tmp);
	}
	return res;
}

unordered_map<string, string> AuditStatusDAO::getMapList()
{
	return auditStatus;
}