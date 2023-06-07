#pragma once
#ifndef _ARCHIVES_CENTER_DO_
#define _ARCHIVES_CENTER_DO_

#include "../DoInclude.h"

/**
 * µµ∞∏ “π‹¿Ì¿‡
 */

class archivesCenterDO
{
	// ≈≈–Ú∫≈
	CC_SYNTHESIZE(uint64_t, serialno, SERIALNO);
	// µµ∞∏ “√˚≥∆
	CC_SYNTHESIZE(string, archivescentername, ARCHIVESCENTERNAME);
	// πÒ∫≈
	CC_SYNTHESIZE(string, cabinetno, CABINETNO);
	// ≤„∫≈
	CC_SYNTHESIZE(string, layerno, LAYERNO);
	// ±‡∫≈
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

