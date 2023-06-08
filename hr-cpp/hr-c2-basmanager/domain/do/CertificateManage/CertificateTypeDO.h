#pragma once
#ifndef _CERTIFICATETYPE_DO_
#define _CERTIFICATETYPE_DO_
#include "../DoInclude.h"
/**
 * 证书类型DO--(证书管理-查询证书类型)--weixiaoman
 */
class CertificateTypeDO {
	//证书类型
	CC_SYNTHESIZE(string, cerType, CerType);
	//唯一标识
	CC_SYNTHESIZE(string, id, Id);
public:
	CertificateTypeDO() {
		cerType = "";
		id = "";
	}
};


#endif // !_CERTIFICATETYPE_DO_
