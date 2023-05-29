#pragma once
#ifndef _AUDITSTATUSMAPPER_H_
#define _AUDITSTATUSMAPPER_H_

#include "Mapper.h"
#include "domain/do/auditStatus/AuditStatusDO.h"

/**
 * 审核状态下拉列表数据库字段匹配映射
 * 负责人：咫尺之书
 */
class AuditStatusMapper : public Mapper<AuditStatusDO>
{
public:
	AuditStatusDO mapper(ResultSet* result) const override
	{
		AuditStatusDO data;
		data.setAuditStatus(result->getString(1));
		return data;
	}
};

#endif // !_AUDITSTATUSMAPPER_H_