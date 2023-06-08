#pragma once
/*
（人员花名册-人员花名册-分页查询员工列表）--洛洛
*/
#ifndef _EMPLOYEE_PAGE_DTO_
#define _EMPLOYEE_PAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmployeeDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeDTO, DTO);
	// 工作单位
	DTO_FIELD(String, ormOrgName);
	DTO_FIELD_INFO(ormOrgName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ormOrgName");
	}
	// 部门名称 t_srforgsector
	DTO_FIELD(String, orgsetorName);
	DTO_FIELD_INFO(orgsetorName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.orgsetorName");
	}
	// 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ygbh");
	}
	// 员工姓名
	DTO_FIELD(String, pimpersonName);
	DTO_FIELD_INFO(pimpersonName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimpersonName");
	}
	// 性别
	DTO_FIELD(String, xb);
	DTO_FIELD_INFO(xb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.xb");
	}
	// 民族
	DTO_FIELD(String, mz);
	DTO_FIELD_INFO(mz) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.mz");
	}
	// 出生日期
	DTO_FIELD(String, csrq);
	DTO_FIELD_INFO(csrq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.csrq");
	}
	// 年龄
	DTO_FIELD(Int32, nl);
	DTO_FIELD_INFO(nl) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.nl");
	}
	// 婚姻状况
	DTO_FIELD(String, hyzk);
	DTO_FIELD_INFO(hyzk) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.hyzk");
	}
	// 籍贯
	DTO_FIELD(String, jg);
	DTO_FIELD_INFO(jg) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.jg");
	}
	// 政治面貌
	DTO_FIELD(String, zzmm);
	DTO_FIELD_INFO(zzmm) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zzmm");
	}
	// 入党时间
	DTO_FIELD(String, rdsj);
	DTO_FIELD_INFO(rdsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.rdsj");
	}
	// 证件号码
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zjhm");
	}
	// 户口性质
	DTO_FIELD(String, hkxz);
	DTO_FIELD_INFO(hkxz) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.hkxz");
	}
	// 户籍地址
	DTO_FIELD(String, hjdz);
	DTO_FIELD_INFO(hjdz) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.hjdz");
	}
	// 社保参缴地
	DTO_FIELD(String, sbcjd);
	DTO_FIELD_INFO(sbcjd) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.sbcjd");
	}
	// 第一学历
	DTO_FIELD(String, dyxl);
	DTO_FIELD_INFO(dyxl) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxl");
	}
	// 第一学历学校类别
	DTO_FIELD(String, xxlb);
	DTO_FIELD_INFO(xxlb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.xxlb");
	}
	// 第一学历学习形式
	DTO_FIELD(String, xxlx);
	DTO_FIELD_INFO(xxlx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.xxlx");
	}
	// 第一学历所学专业
	DTO_FIELD(String, dyxlsxzy);
	DTO_FIELD_INFO(dyxlsxzy) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxlsxzy");
	}
	// 第一学历毕业时间
	DTO_FIELD(String, dyxlbysj);
	DTO_FIELD_INFO(dyxlbysj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxlbysj");
	}
	// 第一学历毕业院校
	DTO_FIELD(String, dyxlbyyx);
	DTO_FIELD_INFO(dyxlbyyx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxlbyyx");
	}
	// 最高学历毕业院校
	DTO_FIELD(String, zgxlbyyx);
	DTO_FIELD_INFO(zgxlbyyx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxlbyyx");
	}
	// 最高学历
	DTO_FIELD(String, zgxl);
	DTO_FIELD_INFO(zgxl) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxl");
	}
	// 最高学历学校类别
	DTO_FIELD(String, zgxxlb);
	DTO_FIELD_INFO(zgxxlb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxxlb");
	}
	// 最高学历学习形式
	DTO_FIELD(String, zgxllx);
	DTO_FIELD_INFO(zgxllx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxllx");
	}
	// 最高学历毕业时间
	DTO_FIELD(String, zgxljssj);
	DTO_FIELD_INFO(zgxljssj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxljssj");
	}
	// 最高学历所学专业
	DTO_FIELD(String, zgxlsxzy);
	DTO_FIELD_INFO(zgxlsxzy) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxlsxzy");
	}
	// 参加工作时间
	DTO_FIELD(String, cjgzsj);
	DTO_FIELD_INFO(cjgzsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.cjgzsj");
	}
	// 工作年限
	DTO_FIELD(Int32, gznx);
	DTO_FIELD_INFO(gznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.gznx");
	}
	// 建筑系统工作时间
	DTO_FIELD(String, tozjdate);
	DTO_FIELD_INFO(tozjdate) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.tozjdate");
	}
	// 建筑系统工作年限
	DTO_FIELD(Int32, zjxtgznx);
	DTO_FIELD_INFO(zjxtgznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zjxtgznx");
	}
	// 局工作时间
	DTO_FIELD(String, dzjbjsj);
	DTO_FIELD_INFO(dzjbjsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dzjbjsj");
	}
	// 局工作年限
	DTO_FIELD(String, bjgznx);
	DTO_FIELD_INFO(bjgznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.bjgznx");
	}
	// 本单位工作时间
	DTO_FIELD(String, dbdwsj);
	DTO_FIELD_INFO(dbdwsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dbdwsj");
	}
	// 本单位工作年限
	DTO_FIELD(String, bdwgznx);
	DTO_FIELD_INFO(bdwgznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.bdwgznx");
	}
	// 所属业务系统
	DTO_FIELD(String, pimMajorseTypeName);
	DTO_FIELD_INFO(pimMajorseTypeName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimMajorseTypeName");
	}
	// 职级
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.rank");
	}
	// 职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zw");
	}
	// 岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.gw");
	}
	// 岗位类别
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.gwType");
	}
	// 绩效考核成绩（近两年）
	DTO_FIELD(String, jxkhcj);
	DTO_FIELD_INFO(jxkhcj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.jxkhcj");
	}
	// 岗位证书
	DTO_FIELD(String, pimQualTypeName);
	DTO_FIELD_INFO(pimQualTypeName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimQualTypeName");
	}
	// 专业技术资格（职称）
	DTO_FIELD(String, careerName);
	DTO_FIELD_INFO(careerName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.careerName");
	}
	// 职称编号
	DTO_FIELD(String, zcbh);
	DTO_FIELD_INFO(zcbh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zcbh");
	}
	// 是否注册会计师
	DTO_FIELD(Int32, sfzckjs);
	DTO_FIELD_INFO(sfzckjs) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.sfzckjs");
	}
	// 注册会计师证书编号
	DTO_FIELD(Int32, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgzsbh");
	}
	// 执（职）业资格证书
	DTO_FIELD(String, pimVocationalCatalogName);
	DTO_FIELD_INFO(pimVocationalCatalogName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimVocationalCatalogName");
	}
	// 入职渠道
	DTO_FIELD(String, rzqd);
	DTO_FIELD_INFO(rzqd) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.rzqd");
	}
	// 合同类别
	DTO_FIELD(String, htlb);
	DTO_FIELD_INFO(htlb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.htlb");
	}
	// 劳动合同性质
	DTO_FIELD(String, contractType);
	DTO_FIELD_INFO(contractType) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.contractType");
	}
	// 签订日期
	DTO_FIELD(String, qsrq);
	DTO_FIELD_INFO(qsrq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.qsrq");
	}
	// 结束日期
	DTO_FIELD(String, jsrq);
	DTO_FIELD_INFO(jsrq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.jsrq");
	}
	// 合同试用期
	DTO_FIELD(String, htsyq);
	DTO_FIELD_INFO(htsyq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.htsyq");
	}
	// 合同期限
	DTO_FIELD(String, htqx);
	DTO_FIELD_INFO(htqx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.htqx");
	}
	// 联系方式
	DTO_FIELD(String, lxdh);
	DTO_FIELD_INFO(lxdh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.lxdh");
	}
	// 员工类型
	DTO_FIELD(String, yglx);
	DTO_FIELD_INFO(yglx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.yglx");
	}

	/*****用不到的字段*****/
	// 人员明细表标识
	DTO_FIELD(String, PCMDETAILID);
	DTO_FIELD_INFO(PCMDETAILID) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.PCMDETAILID");
	}
	// 人员明细表名称
	DTO_FIELD(String, PCMDETAILNAME);
	DTO_FIELD_INFO(PCMDETAILNAME) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.PCMDETAILNAME");
	}
	// 建立人
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.CREATEMAN");
	}
	// ENABLE
	DTO_FIELD(Int32, ENABLE);
	DTO_FIELD_INFO(ENABLE) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ENABLE");
	}
	// 建立时间
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.CREATEDATE");
	}
	// 更新人
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.UPDATEMAN");
	}
	// 更新时间
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.UPDATEDATE");
	}
	// 组织标识
	DTO_FIELD(String, ORMORGID);
	DTO_FIELD_INFO(ORMORGID) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ORMORGID");
	}
	// 部门标识
	DTO_FIELD(String, ORMORGSECTORID);
	DTO_FIELD_INFO(ORMORGSECTORID) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ORMORGSECTORID");
	}
	// FIRSTEDUCATION
	DTO_FIELD(Int32, FIRSTEDUCATION);
	DTO_FIELD_INFO(FIRSTEDUCATION) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.FIRSTEDUCATION");
	}
	// SFZGXL
	DTO_FIELD(Int32, SFZGXL);
	DTO_FIELD_INFO(SFZGXL) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.SFZGXL");
	}
	// 备注
	DTO_FIELD(String, BZ);
	DTO_FIELD_INFO(BZ) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.BZ");
	}
	// 注册会计师专业阶段考试已通过科目数
	DTO_FIELD(String, KSTGKMS);
	DTO_FIELD_INFO(KSTGKMS) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.KSTGKMS");
	}
	// 培训
	DTO_FIELD(String, PX);
	DTO_FIELD_INFO(PX) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.PX");
	}
	// 属性
	DTO_FIELD(String, FIELD);
	DTO_FIELD_INFO(FIELD) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.FIELD");
	}
};

class EmployeePageDTO : public PageDTO<EmployeeDTO::Wrapper>
{
	DTO_INIT(EmployeePageDTO, PageDTO<EmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEE_PAGE_DTO_
