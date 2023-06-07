#pragma once
#ifndef _ARCHIVES_CENTER_DO_
#define _ARCHIVES_CENTER_DO_

#include "../DoInclude.h"

/**
 * �����ҹ�����
 */

class archivesCenterDO
{
	// �����
	CC_SYNTHESIZE(uint64_t, serialno, SERIALNO);
	// ����������
	CC_SYNTHESIZE(string, archivescentername, ARCHIVESCENTERNAME);
	// ���
	CC_SYNTHESIZE(string, cabinetno, CABINETNO);
	// ���
	CC_SYNTHESIZE(string, layerno, LAYERNO);
	// ���
	CC_SYNTHESIZE(string, bnumber, BNUMBER);

public:
	archivesCenterDO()
	{
		serialno = 0;
		archivescentername = "";
		cabinetno = "";
		layerno = "";
		bnumber = "";
	}
};

#endif

