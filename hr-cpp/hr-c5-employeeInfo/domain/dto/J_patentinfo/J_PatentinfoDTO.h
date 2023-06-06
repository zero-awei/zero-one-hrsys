#pragma once


#ifndef _J_PATENT_DTO_
#define _J_PATENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 专利信息传输对象
 */
class J_PatentinfoDTO : public oatpp::DTO
{

public:
	J_PatentinfoDTO() {};
	J_PatentinfoDTO(String zlh, String pimpatentname) :zlh(zlh), pimpatentname(pimpatentname) {};

    DTO_INIT(J_PatentinfoDTO, DTO);

	//CREATEDATE : 建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.createdate");
	}
	//CREATEMAN : 建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.createman");
	}
	//ENABLE : 
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enable");
	}
	//ENCLOLURE : 附件
	DTO_FIELD(String, enclolure);
	DTO_FIELD_INFO(enclolure) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enclolure");
	}
	//JLCZZ : 记录操作者
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlczz");
	}
	//JLGLBH : 记录管理编号
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlglbh");
	}
	//JLSPZT : 审批状态
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlspzt");
	}
	//JLSS : 记录所属
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlss");
	}
	//ORGID : 组织标识1
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.orgid");
	}
	//ORGSECTORID : 部门标识1
	DTO_FIELD(String, orgsectorid);
	DTO_FIELD_INFO(orgsectorid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.orgsectorid");
	}
	//ORMORGID : 组织标识2
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ormorgid");
	}
	//ORMORGSECTORID : 部门标识2
	DTO_FIELD(String, ormorgsectorid);
	DTO_FIELD_INFO(ormorgsectorid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ormorgsectorid");
	}
	//PIMPATENTID : 专利信息编码
	DTO_FIELD(String, pimpatentid);
	DTO_FIELD_INFO(pimpatentid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
	}
	//PIMPATENTNAME : 专利名称
	DTO_FIELD(String, pimpatentname);
	DTO_FIELD_INFO(pimpatentname) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentname");
	}
	//PIMPERSONID : 人员信息标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpersonid");
	}
	//PIMPERSONNAME : 员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpersonname");
	}
	//REASON : 拒绝原因
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.reason");
	}
	//UPDATEDATE : 更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updatedate");
	}
	//UPDATEMAN : 更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updateman");
	}
	//YGBH : 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ygbh");
	}
	//ZLH:专利号
	DTO_FIELD(String, zlh);
	DTO_FIELD_INFO(zlh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlh");
	}
	//ZLHQSJ : 专利获取时间
	DTO_FIELD(String, zlhqsj);
	DTO_FIELD_INFO(zlhqsj) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlhqsj");
	}
	//ZLPZGB : 专利批准国别
	DTO_FIELD(String, zlpzgb);
	DTO_FIELD_INFO(zlpzgb) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlpzgb");
	}

};

/**
 * 修改专利信息传输对象
 */
	class ModifyPatentinfoDTO : public oatpp::DTO
{

public:

	DTO_INIT(ModifyPatentinfoDTO, DTO);

	//PIMPATENTID : 专利信息编码
	DTO_FIELD(String, pimpatentid);
	DTO_FIELD_INFO(pimpatentid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
	}
	//ZLH:专利号
	DTO_FIELD(String, zlh);
	DTO_FIELD_INFO(zlh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlh");
	}
	//PIMPATENTNAME : 专利名称
	DTO_FIELD(String, pimpatentname);
	DTO_FIELD_INFO(pimpatentname) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentname");
	}
	//ZLHQSJ : 专利获取时间
	DTO_FIELD(String, zlhqsj);
	DTO_FIELD_INFO(zlhqsj) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlhqsj");
	}
	//ZLPZGB : 专利批准国别
	DTO_FIELD(String, zlpzgb);
	DTO_FIELD_INFO(zlpzgb) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlpzgb");
	}
	//ENCLOLURE : 附件
	DTO_FIELD(String, enclolure);
	DTO_FIELD_INFO(enclolure) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enclolure");
	}
	//UPDATEDATE : 更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updatedate");
	}
	//UPDATEMAN : 更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updateman");
	}

};







/**
 * 分页传输对象
 */
class J_PatentinfoPageDTO : public PageDTO<J_PatentinfoDTO::Wrapper>
{
    DTO_INIT(J_PatentinfoPageDTO, PageDTO<J_PatentinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
