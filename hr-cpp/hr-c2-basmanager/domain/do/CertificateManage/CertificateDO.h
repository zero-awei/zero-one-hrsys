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

//两个文件同名，发生冲突，暂时合并在一起了
class CertificateDO
{
/**
 * 离职员工数据库实体类--pine
 */
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(string, age, Age);
	// 组织
	CC_SYNTHESIZE(string, organization, Organization);
	// 部门
	CC_SYNTHESIZE(string, department, Department);
	// 职级
	CC_SYNTHESIZE(string, rank, Rank);
	// 通讯地址
	CC_SYNTHESIZE(string, mail_address, Mail_address);
	// 家庭联系人
	CC_SYNTHESIZE(string, family_contact, Family_contact);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, family_contact_number, Family_contact_nuimber);
/**
 * 证书管理数据库实体类
 */
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
	CertificateDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		organization = "";
		department = "";
		rank = "";
		mail_address = "";
		family_contact = "";
		family_contact_number = "";
	}
};

#endif // !_FPRMERRMPLOYEES_DO_