#pragma once
#ifndef _ARCHIVEDO_H_
#define _ARCHIVEDO_H_

#include "../DoInclude.h"
/**
 * µµ°¸ÊÒĞÅÏ¢ÊµÌå
 */
class ArchiveDO
{
	// ÅÅĞòºÅ
	CC_SYNTHESIZE(int32_t, sortid, sortID);
	// µµ°¸ÊÒÃû³Æ
	CC_SYNTHESIZE(string, archivename, archiveName);
	// ¹ñÊı
	CC_SYNTHESIZE(int32_t, cabinetnum, cabinetNum);
	// ²ãÊı
	CC_SYNTHESIZE(int32_t, layernum, layerNum);
	// ±àºÅ
	CC_SYNTHESIZE(int32_t, numid, numID);
public:
	ArchiveDO() {
	
		sortid = 0;
		archivename = "";
		cabinetnum = 0;
		layernum = 0;
		numid = 0;
	
	
	
	}
	//·Ö±ğÎªÅÅĞòºÅ£¬µµ°¸ÊÒÃû³Æ£¬¹ñÊı£¬²ãÊı£¬±àºÅ
	ArchiveDO(int sortid,string archivename ,int cabinetnum,int layernum,int numid)
	{
		this->sortid = sortid;
		this->archivename = archivename;
		this->cabinetnum = cabinetnum;
		this->layernum = layernum;
		this->numid = numid;
	}
};

#endif