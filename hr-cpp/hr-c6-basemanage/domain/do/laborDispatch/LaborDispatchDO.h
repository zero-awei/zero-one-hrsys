#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:11:50

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
#ifndef _LABORDISPATCHDO_H_
#define _LABORDISPATCHDO_H_

class LaborDispatchDO
{
	CC_SYNTHESIZE(string, enable, _Enable);
	//劳务派遣公司管理名称
	CC_SYNTHESIZE(string, name, Name);
	//劳务派遣公司管理标识
	CC_SYNTHESIZE(string, id, Id);
	//所属单位
	CC_SYNTHESIZE(string,unit, Unit);
	//建立时间
	CC_SYNTHESIZE(string, createdate, Createdate);
	//建立人
	CC_SYNTHESIZE(string, createman, Createman);
	//更新人
	CC_SYNTHESIZE(string, updateman, Updateman);
	//更新时间
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	//经营范围
	CC_SYNTHESIZE(string, jyfw, Jyfw);
	//联系地址
	CC_SYNTHESIZE(string, lxdz, Lxdz);
	//联系方式
	CC_SYNTHESIZE(string, lxfs, Lxfs);
	//联系人
	CC_SYNTHESIZE(string, lxr, Lxr);
	//公司简介
	CC_SYNTHESIZE(string, gsjj, Gsjj);
	//人员信息标识
	CC_SYNTHESIZE(string, pimpersonid, Pimpersonid);
	// 组织标识
	CC_SYNTHESIZE(string, ormorgid, Ormorgid);
	//注册本金
	CC_SYNTHESIZE(string, regcapital, Regcapital);
	//法人
	CC_SYNTHESIZE(string, legalperson, Legalperson);
	//字段
	CC_SYNTHESIZE(string, ziduan, Ziduan);

public:
	LaborDispatchDO() {
		enable = "";
		name = "";
		id = "";
		unit = "";
		createdate = "";
		createman = "";
		updateman = "";
		updatedate = "";
		jyfw = "";
		lxdz = "";
		lxfs = "";
		lxr = "";
		gsjj = "";
		pimpersonid = "";
		ormorgid = "";
		regcapital = "";
		legalperson = "";
		ziduan = "";
	}
};

#endif // !_LABORDISPATCHDO_H_