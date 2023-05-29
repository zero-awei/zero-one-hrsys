#pragma once
#ifndef _AUDITSTATUSSERVICE_H_
#define _AUDITSTATUSSERVICE_H_

#include "domain/dto/pullList/PullListDTO.h"

/**
 * 费用类别下拉列表服务实现
 * 负责人：咫尺之书
 */
class AuditStatusService
{
public:
	// 查询费用类别列表
	PullListDTO::Wrapper listAll();
};

#endif // !_AUDITSTATUSSERVICE_H_