#pragma once
#ifndef _AUDITSTATUSDAO_H_
#define _AUDITSTATUSDAO_H_

#include "BaseDAO.h"
#include "domain/do/auditStatus/AuditStatusDO.h"

class AuditStatusDAO : public BaseDAO
{
private:
	// 审核状态对应哈希表
	unordered_map<string, string> auditStatus = {
		{"10", u8"待审核"},
		{"20", u8"审核中"},
		{"30", u8"审核通过"},
		{"40", u8"审核未通过"}
	};
public:
	// 查询数据
	list<AuditStatusDO> listAll();
	// 返回下拉列表
	unordered_map<string, string> getMapList();
};

#endif // !_AUDITSTATUSDAO_H_