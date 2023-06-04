#pragma once
#ifndef _TRAININGRECORDDO_H_
#define _TRAININGRECORDDO_H_
#include "../DoInclude.h"

class TrainingRecordDO {

	//培训人员主键标识
	CC_SYNTHESIZE(string, TRMTRIANPERSONID, _TRMTRIANPERSONID);
	//培训班级
	CC_SYNTHESIZE(string, PXBJ, _PXBJ);
	//培训开始时间
	CC_SYNTHESIZE(string, TRAINBEGIN, _TRAINBEGIN);
	//培训结束时间
	CC_SYNTHESIZE(string, TRAINEND, _TRAINEND);
	//培训课程
	CC_SYNTHESIZE(string, PXKC, _PXKC);
	//培训机构
	CC_SYNTHESIZE(string, TRMTRAINAGENCYNAME, _TRMTRAINAGENCYNAME);
	//培训结果
	CC_SYNTHESIZE(string, TRAINRES, _TRAINRES);
	//分数
	CC_SYNTHESIZE(string, FS, _FS);

};

#endif