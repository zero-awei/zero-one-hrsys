#pragma once
#ifndef _CERTIFICATETYPE_DO_
#define _CERTIFICATETYPE_DO_
#include "../DoInclude.h"

class CertificateTypeDO {
	//证书类型
	CC_SYNTHESIZE(string, cerType, CerType);
public:
	CertificateTypeDO() {
		cerType = "";
	}
};


#endif // !_CERTIFICATETYPE_DO_
