#include "stdafx.h"
#include "TemporaryStaffDAO.h"
#include "TemporaryStaffMapper.h"
#include <sstream>

uint64_t TemporaryStaffDAO::count(const TempStaffQuery::Wrapper& query)
{
	return uint64_t();
}

list<TemporaryStaffDO> TemporaryStaffDAO::selectWithPage(const TempStaffQuery::Wrapper& query)
{
	return list<TemporaryStaffDO>();
}

list<TemporaryStaffDO> TemporaryStaffDAO::selectByName(const string& name)
{
	return list<TemporaryStaffDO>();
}
