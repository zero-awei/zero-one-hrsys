#pragma once
#ifndef _RETIRED_EMPLPYEES_DO_
#define _RETIRED_EMPLPYEES_DO_
#include "../DoInclude.h"
/*
 离退休员工DO--（人员花名册）--pine
 (对应数据库表t_pcmydjdmx：异动借调明细 与 t_pcmydmx：异动明细)
 */

class RetiredEmployeesDO
{
	// 员工编号
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// 员工id（）PIMPERSONID
	CC_SYNTHESIZE(string, pimpersonid, pimpersonid);
	//姓名+编号
	CC_SYNTHESIZE(string, idAndName, idAndName);
	// 员工姓名
	CC_SYNTHESIZE(string, pimpersonname, pimpersonname);//修改
	// 性别
	CC_SYNTHESIZE(string, xb, xb);
	// 年龄
	CC_SYNTHESIZE(string, nj, nj);
	// 通讯地址
	CC_SYNTHESIZE(string, postaladdress, postaladdress);
	// 退休地
	CC_SYNTHESIZE(string, retiPlace, retiPlace);
	// 家庭联系人
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	// 组织
	CC_SYNTHESIZE(string, zz, zz);
	// 部门
	CC_SYNTHESIZE(string, bm, bm);
	// 职级
	CC_SYNTHESIZE(string, rank, rank);
	//退休前职务
	CC_SYNTHESIZE(string, yzw, yzw);
	//退休前岗位
	CC_SYNTHESIZE(string, ygw, ygw);
	//退休时间
	CC_SYNTHESIZE(string, txdq, txdq);
	//实际退休时间
	CC_SYNTHESIZE(string, sjtxrq, sjtxrq);
	//手机号码
	CC_SYNTHESIZE(string, lxdh, lxdh);
	//审批的养老金额
	CC_SYNTHESIZE(string, spdylje, spdylje);
public:
	RetiredEmployeesDO() {
		ygbh = "";
		pimpersonid = "";
		pimpersonname = "";
		xb = "";
		nj = "-1";
		postaladdress = "";
		retiPlace = "";
		jtlxr = "";
		jtlxrdh = "";
		zz = "";
		bm = "";
		rank = "";
		yzw = "";
		ygw = "";
		txdq = "";
		sjtxrq = "";
		lxdh = "";
		spdylje = "";

	}
};

#endif // !_SAMPLE_DO_
