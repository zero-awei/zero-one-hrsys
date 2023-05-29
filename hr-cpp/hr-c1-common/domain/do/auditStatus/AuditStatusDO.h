#pragma once
#ifndef _AUDITSTATUSDO_H_
#define _AUDITSTATUSDO_H_

#include "../DoInclude.h"

/**
 * 审核状态下拉列表DO
 * 负责人：咫尺之书
 */
class AuditStatusDO
{
	// 代码项名称
	CC_SYNTHESIZE(string, auditStatus, AuditStatus);
	// 代码项值
	CC_SYNTHESIZE(string, code, Code);
public:
	AuditStatusDO()
	{
		code = "";
		auditStatus = "";
	}

	AuditStatusDO(string code_, string level_)
	{
		code = code_;
		auditStatus = level_;
	}
};

#endif // !_AUDITSTATUSDO_H_