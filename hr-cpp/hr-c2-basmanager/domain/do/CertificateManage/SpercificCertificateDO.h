#pragma once
/**
 *  基础管理 —— 证书管理 —— 查询，更新指定证书 —— 楚孟献
 */

#ifndef _SPERCIFIC_CERTIFICATE_DO_
#define _SPERCIFIC_CERTIFICATE_DO_
#include "../DoInclude.h"

class SpercificCertificateDO
{
	/**
	 * 指定证书管理数据库实体类
	 */
	// 姓名
	CC_SYNTHESIZE(string, pimperSonName, PimperSonName);
	// 证书编号
	CC_SYNTHESIZE(string, zgzsbh, Zgzsbh);
	// 证书类型
	CC_SYNTHESIZE(string, zslx, Zslx);
	// 证书名称
	CC_SYNTHESIZE(string, pimVocationalName, PimVocationalName);
	// 签发机构
	CC_SYNTHESIZE(string, zgsydw, Zgsydw);
	// 注册编号
	CC_SYNTHESIZE(string, REGISNUMBER, regisNumber)
	// 注册单位
	CC_SYNTHESIZE(string, zcdw, Zcdw);
	// 社保缴纳单位
	CC_SYNTHESIZE(string, SOCSECPAYUNIT, SOCSECPAYUNIT);
	// 一建配套B证编号
	CC_SYNTHESIZE(string, bcardNumber, BcardNumber);

	// 证书获得情况
	
	// 签发日期  required
	CC_SYNTHESIZE(string, zghqrq, Zghqrq); 
	// 初始注册时间
	CC_SYNTHESIZE(string, CSZCSJ, CSZCSJ);
	// 续注册时间
	CC_SYNTHESIZE(string, XZCSJ, XZCSJ);
	// 失效日期
	CC_SYNTHESIZE(string, sxrq, Sxrq);
	// 年审情况
	CC_SYNTHESIZE(string, NSQK, NSQK);
	// 使用情况
	CC_SYNTHESIZE(string, SYQK, SYQK);
	// 变更情况
	CC_SYNTHESIZE(string, ALTERATION, ALTERATION);

	//////////////////////////////////////////////////////////////
	// 以下为非前端显示字段
	// 执（职）业资格信息标识   PRIMARY KEY (`PIMVOCATIONALID`),
	CC_SYNTHESIZE(string, PIMVOCATIONALID, PIMVOCATIONALID);
	// 人员信息标识 FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// 组织标识 FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);
	// 岗位（技能）证书目录ID
	CC_SYNTHESIZE(string, PIMQUALTYPEID, PIMQUALTYPEID);
public:
	SpercificCertificateDO() {};

};

#endif // !_FPRMERRMPLOYEES_DO_