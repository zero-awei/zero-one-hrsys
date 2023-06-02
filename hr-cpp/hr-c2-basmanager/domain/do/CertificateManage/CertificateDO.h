#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CERTIFICATE_DO_
#define _CERTIFICATE_DO_
#include "../DoInclude.h"

class CertificateDO
{
	/**
	 * 证书管理数据库实体类
	 */
	 // 员工基本信息表ID,同员工ID
	CC_SYNTHESIZE(uint64_t, ygbh, Ygbh);
	// 证书与人员姓名（模糊查找）
	CC_SYNTHESIZE(string, nameOfPAndV, NameOfPAndV);
	// 姓名
	CC_SYNTHESIZE(string, pimperSonName, PimperSonName);
	// 员工状态 
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	// 组织   t_srforg 需要连表操作获取组织名称
	CC_SYNTHESIZE(string, zz, ZZ);
	// 证书编号
	CC_SYNTHESIZE(string, pimvocationalid, Pimvocationalid);
	// 一建配套B证编号
	CC_SYNTHESIZE(string, bcardNumber, BcardNumber);
	// 证书名称
	CC_SYNTHESIZE(string, pimVocationalName, PimVocationalName);
	// 证书类型
	CC_SYNTHESIZE(string, zslx, Zslx);
	// 签发日期
	CC_SYNTHESIZE(string, zghqrq, Zghqrq);
	// 签发机构
	CC_SYNTHESIZE(string, zgsydw, Zgsydw);
	// 注册单位
	CC_SYNTHESIZE(string, zcdw, Zcdw);
	// 发证有效期
	CC_SYNTHESIZE(string, fzyxq, Fzyxq);
	// 失效日期
	CC_SYNTHESIZE(string, sxrq, Sxrq);
	/*新建证书多出的三个字段*/
	//年审情况
	CC_SYNTHESIZE(string, nsqk, NSQK);
	// 使用情况
	CC_SYNTHESIZE(string, syqk, SYQK);
	// 变更情况
	CC_SYNTHESIZE(string, alteration, ALTERATION);

	// 证书剩余日期 表内没有
	//////////////////////////////////////////////////////////////
	// 以下为非前端显示字段
	// 人员信息标识 FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// 组织标识 FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);


public:
	CertificateDO() {
		ygbh = 0;
		nameOfPAndV = "";
		pimperSonName = "";
		ygzt = "";
		zz = "";
		pimvocationalid = "";
		bcardNumber = "";
		pimVocationalName = "";
		zslx = "";
		zghqrq = "";
		zgsydw = "";
		zcdw = "";
		fzyxq = "";
		sxrq = "";
	}
};

#endif // !_FPRMERRMPLOYEES_DO_