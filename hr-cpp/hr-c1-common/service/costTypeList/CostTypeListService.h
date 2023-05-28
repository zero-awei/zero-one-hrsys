#pragma once
#ifndef _COSTTYPELISTSERVICE_H_
#define _COSTTYPELISTSERVICE_H_

#include "domain/dto/pullList/PullListDTO.h"

/**
 * 费用类别下拉列表服务实现
 * 负责人：咫尺之书
 */
class CostTypeListService
{
public:
	// 查询费用类别列表
	PullListDTO::Wrapper listAll();
};

#endif // !_COSTTYPELISTSERVICE_H_