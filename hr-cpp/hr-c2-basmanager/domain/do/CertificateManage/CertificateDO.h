#pragma once
//证书管理数据库实体类

#ifndef _CERTIFICATE_DO_
#define _CERTIFICATE_DO_
#include "../DoInclude.h"

/**
 * 证书管理数据库实体类
 */
class CertificateDO 
{
	// 员工基本信息表ID,同员工ID
	CC_SYNTHESIZE(uint64_t, ygbh, ygbh);
	// 姓名
	CC_SYNTHESIZE(string, pimperSonName, pimperSonName);
	// 员工状态 
	CC_SYNTHESIZE(string, ygzt, ygzt);
	// 组织   t_srforg 需要连表操作获取组织名称
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// 证书编号
	CC_SYNTHESIZE(string, zgzsbh, zgzsbh);
	// 一建配套B证编号
	CC_SYNTHESIZE(string, bcardNumber, bcardNumber);
	// 证书名称
	CC_SYNTHESIZE(string, pimVocationalName, pimVocationalName);
	// 证书类型
	CC_SYNTHESIZE(string, zslx, zslx);
	// 签发日期
	CC_SYNTHESIZE(string, zghqrq, zghqrq);
	// 签发机构
	CC_SYNTHESIZE(string, zgsydw, zgsydw);
	// 注册单位
	CC_SYNTHESIZE(string, zcdw, zcdw);
	// 发证有效期
	CC_SYNTHESIZE(string, fzyxq, fzyxq);
	// 失效日期
	CC_SYNTHESIZE(string, sxrq, sxrq);
	// 证书剩余日期 表内没有
	//////////////////////////////////////////////////////////////
	// 以下为非前端显示字段
	// 人员信息标识 FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// 组织标识 FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);
public:
	CertificateDO() {	}
};

#endif 