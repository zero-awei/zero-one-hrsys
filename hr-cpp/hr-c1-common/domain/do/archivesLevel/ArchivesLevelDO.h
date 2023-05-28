#pragma once
#ifndef _ARCHIVESLEVELDO_H_
#define _ARCHIVESLEVELDO_H_

#include "../DoInclude.h"
/**
 * 档案室层级下拉列表DO
 * 负责人：咫尺之书
 */
class ArchivesLevelDO
{
	// 代码项名称
	CC_SYNTHESIZE(string, archivesLevel, ArchivesLevel);
	// 代码项值
	CC_SYNTHESIZE(int, code, Code);
};

#endif // !_ARCHIVESLEVELDO_H_