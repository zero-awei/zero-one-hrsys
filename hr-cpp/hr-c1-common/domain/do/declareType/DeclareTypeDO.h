#pragma once
#ifndef _DECLARETYPEDO_H_
#define _DECLARETYPEDO_H_

#include "../DoInclude.h"
/**
 * 申报类型下拉列表DO
 * 负责人：咫尺之书
 */
class DeclareTypeDO
{
	// 代码项名称
	CC_SYNTHESIZE(string, declareType, DeclareType);
	// 代码项值
	CC_SYNTHESIZE(int, code, Code);
};

#endif // !_DECLARETYPEDO_H_