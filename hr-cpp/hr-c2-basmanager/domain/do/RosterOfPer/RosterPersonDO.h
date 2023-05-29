#pragma once
#ifndef _ROSTERPERSON_DO_
#define _ROSTERPERSON_DO_
#include "../DoInclude.h"
/**
 * 人员花名册信息查询功能数据库实体，搜索框使用--(人员花名册-人员花名册-分页查询员工列表)--weixiaoman
 */

class RosterPersonDO {
	//工作单位
	CC_SYNTHESIZE(string, ormOrgName, ormOrgName);
	//部门名称 t_srforgsector
	CC_SYNTHESIZE(string, orgsetorName, orgsetorName);
	//员工编号
	CC_SYNTHESIZE(string, ygbh, ygbh);
	//员工姓名
	CC_SYNTHESIZE(string, pimpersonName, pimpersonName);
	//性别
	CC_SYNTHESIZE(string, xb, xb);
	//民族
	CC_SYNTHESIZE(string, mz, mz);
	//出生日期
	CC_SYNTHESIZE(string, csrq, csrq);
	//年龄
	CC_SYNTHESIZE(int, nl, nl);
	//婚姻状况
	CC_SYNTHESIZE(string, hyzk, hyzk);
	//籍贯
	CC_SYNTHESIZE(string, jg, jg);
	//政治面貌
	CC_SYNTHESIZE(string, zzmm, zzmm);
	//入党时间
	CC_SYNTHESIZE(string, rdsj, rdsj);
	//证件号码
	CC_SYNTHESIZE(string, zjhm, zjhm);
	//户口性质 
	CC_SYNTHESIZE(string, hkxz, hkxz);
	//户籍地址
	CC_SYNTHESIZE(string, hjdz, hjdz);
	//社保参缴地		
	CC_SYNTHESIZE(string, sbcjd, sbcjd);
	//第一学历 
	CC_SYNTHESIZE(string, dyxl, dyxl);
	//第一学历学校类别 
	CC_SYNTHESIZE(string, xxlb, xxlb);
	//第一学历学习形式 
	CC_SYNTHESIZE(string, xxlx, xxlx);
	//第一学历所学专业 
	CC_SYNTHESIZE(string, dyxlsxzy, dyxlsxzy);
	//第一学历毕业时间 
	CC_SYNTHESIZE(string, dyxlbysj, dyxlbysj);
	//第一学历毕业院校 
	CC_SYNTHESIZE(string, dyxlbyyx, dyxlbyyx);
	//最高学历毕业院校 
	CC_SYNTHESIZE(string, zgxlbyyx, zgxlbyyx);
	//最高学历 
	CC_SYNTHESIZE(string, zgxl, zgxl);
	//最高学历学校类别 
	CC_SYNTHESIZE(string, zgxxlb, zgxxlb);
	//最高学历学习形式 
	CC_SYNTHESIZE(string, zgxllx, zgxllx);
	//最高学历毕业时间 
	CC_SYNTHESIZE(string, zgxljssj, zgxljssj);
	//最高学历所学专业 
	CC_SYNTHESIZE(string, zgxlsxzy, zgxlsxzy);
	//参加工作时间 
	CC_SYNTHESIZE(string, cjgzsj, cjgzsj);
	//工作年限 
	CC_SYNTHESIZE(int, gznx, gznx);
	//建筑系统工作时间 
	CC_SYNTHESIZE(string, tozjdate, tozjdate);
	//建筑系统工作年限 
	CC_SYNTHESIZE(int, zjxtgznx, zjxtgznx);
	//局工作时间 
	CC_SYNTHESIZE(string, dzjbjsj, dzjbjsj);
	//局工作年限 
	CC_SYNTHESIZE(string, bjgznx, bjgznx);
	//本单位工作时间
	CC_SYNTHESIZE(string, dbdwsj, dbdwsj);
	//本单位工作年限
	CC_SYNTHESIZE(string, bdwgznx, bdwgznx);
	//所属业务系统 
	CC_SYNTHESIZE(string, pimMajorseTypeName, pimMajorseTypeName);
	//职级 
	CC_SYNTHESIZE(string, rank, rank);
	//职务 
	CC_SYNTHESIZE(string, zw, zw);
	//岗位 
	CC_SYNTHESIZE(string, gw, gw);
	//岗位类别 
	CC_SYNTHESIZE(string, gwType, gwType);
	//绩效考核成绩（近两年） 
	CC_SYNTHESIZE(string, jxkhcj, jxkhcj);
	//岗位证书 
	CC_SYNTHESIZE(string, pimQualTypeName, pimQualTypeName);
	//专业技术资格（职称） 
	CC_SYNTHESIZE(string, careerName, careerName);
	//职称编号 
	CC_SYNTHESIZE(string, zcbh, zcbh);
	//是否注册会计师
	CC_SYNTHESIZE(int, sfzckjs, sfzckjs);
	//注册会计师证书编号 
	CC_SYNTHESIZE(int, zgzsbh, zgzsbh);
	//执（职）业资格证书 
	CC_SYNTHESIZE(string, pimVocationalCatalogName, pimVocationalCatalogName);
	//入职渠道 
	CC_SYNTHESIZE(string, rzqd, rzqd);
	//合同类别 
	CC_SYNTHESIZE(string, htlb, htlb);
	//劳动合同性质 
	CC_SYNTHESIZE(string, contractType, contractType);
	//签订日期 
	CC_SYNTHESIZE(string, qsrq, qsrq);
	//结束日期 
	CC_SYNTHESIZE(string, jsrq, jsrq);
	//合同试用期 
	CC_SYNTHESIZE(string, htsyq, htsyq);
	//合同期限
	CC_SYNTHESIZE(string, htqx, htqx);
	//联系方式
	CC_SYNTHESIZE(string, lxdh, lxdh);
	//员工类型
	CC_SYNTHESIZE(string, yglx, yglx);

	/*****用不到的字段*****/
	//人员明细表标识
	CC_SYNTHESIZE(string, PCMDETAILID, PCMDETAILID);
	//人员明细表名称
	CC_SYNTHESIZE(string, PCMDETAILNAME, PCMDETAILNAME);
	//建立人
	CC_SYNTHESIZE(string, CREATEMAN, CREATEMAN);
	//ENABLE
	CC_SYNTHESIZE(int, ENABLE, ENABLE);
	//建立时间
	CC_SYNTHESIZE(string, CREATEDATE, CREATEDATE);
	//更新人
	CC_SYNTHESIZE(string, UPDATEMAN, UPDATEMAN);
	//更新时间
	CC_SYNTHESIZE(string, UPDATEDATE, UPDATEDATE);
	//组织标识
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);
	//部门标识
	CC_SYNTHESIZE(string, ORMORGSECTORID, ORMORGSECTORID);
	//FIRSTEDUCATION
	CC_SYNTHESIZE(int, FIRSTEDUCATION, FIRSTEDUCATION);
	//SFZGXL
	CC_SYNTHESIZE(int, SFZGXL, SFZGXL);
	//备注
	CC_SYNTHESIZE(string, BZ, BZ);
	//注册会计师专业阶段考试已通过科目数
	CC_SYNTHESIZE(string, KSTGKMS, KSTGKMS);
	//培训
	CC_SYNTHESIZE(string, PX, PX);
	//属性
	CC_SYNTHESIZE(string, FIELD, FIELD);

public:
	RosterPersonDO() { 
		this->gznx = 0; 
		this->nl = 0; 
		this->sfzckjs = 0; 
		this->zgzsbh = 0; 
		this->zjxtgznx = 0; 

		//用不到的字段
		this->ENABLE = 0;
		this->FIRSTEDUCATION = 0;
		this->SFZGXL = 0;
	};
};

#endif // !_ROSTERPERSON_DO_

