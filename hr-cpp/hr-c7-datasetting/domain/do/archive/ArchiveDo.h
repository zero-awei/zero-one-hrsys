#pragma once
#ifndef _ARCHIVEDO_H_
#define _ARCHIVEDO_H_

#include "../DoInclude.h"
/**
 * 档案室信息实体
 */
class archiveDO
{
	// 排序号
	CC_SYNTHESIZE(int32_t, sortID, sortid);
	// 档案室名称
	CC_SYNTHESIZE(string, archiveName, archivename);
	// 柜数
	CC_SYNTHESIZE(int32_t, cabinetNum, cabinetnum);
	// 层数
	CC_SYNTHESIZE(int32_t, layerNum, layernum);
	// 编号
	CC_SYNTHESIZE(int32_t, numID, numid);
public:
	archiveDO() {}
	//分别为排序号，档案室名称，柜数，层数，编号
	archiveDO(int sortid,string archivename ,int cabinetnum,int layernum,int numid)
	{
		this->sortID = sortid;
		this->archiveName = archivename;
		this->cabinetNum = cabinetnum;
		this->layerNum = layernum;
		this->numID = numid;
	}
};

#endif