#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 20:22:16

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
#ifndef _LABORDISPATCHDTO_H_
#define _LABORDISPATCHDTO_H_

#include "../../GlobalInclude.h"
#include "SnowFlake.h"
#include <string>
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询传输对象
 */
class LaborDispatchDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchDTO, DTO);
	//公司管理标识
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYID");
	}
	//公司名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYNAME");
	}
	//所属单位
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.ORGNAME");
	}
	//联系地址
	DTO_FIELD(String, lxdz);
	DTO_FIELD_INFO(lxdz) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXDZ");
	}
	//联系人
	DTO_FIELD(String, lxr);
	DTO_FIELD_INFO(lxr) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXR");
	}
	//联系方式
	DTO_FIELD(String, lxfs);
	DTO_FIELD_INFO(lxfs) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXFS");
	}
	//法人
	DTO_FIELD(String, legalperson);
	DTO_FIELD_INFO(legalperson) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LEGALPEROSN");
	}
	//注册本金
	DTO_FIELD(String, regcapital);
	DTO_FIELD_INFO(regcapital) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.REGCAPITAL");
	}
	//更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.UPDATEDATE");
	}
};

/**
* 修改传输对象
*/
class LaborDispatchModifyDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchModifyDTO, DTO);
	//公司名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYNAME");
	}
	//所属单位
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYID");
	}
	//联系地址
	DTO_FIELD(String, lxdz);
	DTO_FIELD_INFO(lxdz) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXDZ");
	}
	//联系人
	DTO_FIELD(String, lxr);
	DTO_FIELD_INFO(lxr) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXR");
	}
	//联系方式
	DTO_FIELD(String, lxfs);
	DTO_FIELD_INFO(lxfs) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXFS");
	}
	//法人
	DTO_FIELD(String, legalperson);
	DTO_FIELD_INFO(legalperson) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LEGALPERSON");
	}
	//注册本金
	DTO_FIELD(String, regcapital);
	DTO_FIELD_INFO(regcapital) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.REGCAPITAL");
	}
	//公司简介
	DTO_FIELD(String, gsjj);
	DTO_FIELD_INFO(gsjj) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.GSJJ");
	}
};

/**
 * 删除传输对象
 */
class LaborDispatchRemoveDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchRemoveDTO, DTO);
	//劳务派遣公司管理标识
	DTO_FIELD(List<String>, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYID");
	}
};


/**
 * 导出传输对象
 */
class LaborDispatchExportDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchExportDTO, DTO);
	//字段列表
	DTO_FIELD(List<String>, ziduan) = {"PIMLABOURCAMPANYNAME","ORGNAME","LXDZ","LXR","LXFS","REGCAPITAL","LEGALPEROSN","UPDATEDATE" };
	DTO_FIELD_INFO(ziduan) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.ZIDUAN");
	}
};
/**
 * 分页传输对象
 */
class LaborDispatchPageDTO : public PageDTO<LaborDispatchDTO::Wrapper>
{
	DTO_INIT(LaborDispatchPageDTO, PageDTO<LaborDispatchDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LABORDISPATCHDTO_H_