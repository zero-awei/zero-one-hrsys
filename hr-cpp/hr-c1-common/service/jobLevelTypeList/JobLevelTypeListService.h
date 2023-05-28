#pragma once
#ifndef _JOBLEVELTYPELISTSERVICE_H_
#define _JOBLEVELTYPELISTSERVICE_H_

#include "domain/dto/pullList/PullListDTO.h"

/**
 * 职称等级下拉列表服务实现
 * 负责人：咫尺之书
 */
class JobLevelTypeListService
{
public:
	// 查询职称等级列表
	PullListDTO::Wrapper listAll();
};

#endif // !_JOBLEVELTYPELISTSERVICE_H_