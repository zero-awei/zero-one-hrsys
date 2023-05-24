#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 16:45:32

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
#ifndef _POSTDETAIL_DTO_
#define _POSTDETAIL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 岗位设置 - 查询指定岗位详情DTO
 */
class PostDetailDTO : public oatpp::DTO
{
	DTO_INIT(PostDetailDTO, DTO);

	// 排序标号*
	DTO_FIELD(UInt64, xh);
	DTO_FIELD_INFO(xh) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.xh");
	}
	// 岗位分类*
	DTO_FIELD(String, gwfl);
	DTO_FIELD_INFO(gwfl) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.gwfl");
	}
	// 是否保密岗*
	DTO_FIELD(String, isConfidential);
	DTO_FIELD_INFO(isConfidential) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.isConfidential");
	}
	// 岗位集名称*
	DTO_FIELD(String, ormPostName);
	DTO_FIELD_INFO(ormPostName) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormPostName");
	}
	// 建议交流年限*
	DTO_FIELD(UInt64, nx);
	DTO_FIELD_INFO(nx) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.nx");
	}
	// 必须交流年限*
	DTO_FIELD(UInt64, bxjlnx);
	DTO_FIELD_INFO(bxjlnx) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.bxjlnx");
	}
	// 是否关键岗位*
	DTO_FIELD(String, isKeyPostion);
	DTO_FIELD_INFO(isKeyPostion) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.isKeyPostion");
	}
	// 岗位性质*
	DTO_FIELD(String, postNature);
	DTO_FIELD_INFO(postNature) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.postNature");
	}
	// 启用标识*
	DTO_FIELD(String, startStopSign);
	DTO_FIELD_INFO(startStopSign) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.startStopSign");
	}

	// 岗位集标识
	DTO_FIELD(String, ormPostId);
	DTO_FIELD_INFO(ormPostId) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormPostId");
	}


	// 建立人
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.createMan");
	}
	// 更新时间
	DTO_FIELD(String, updateDate);
	DTO_FIELD_INFO(updateDate) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.updateDate");
	}
	// 更新人
	DTO_FIELD(String, updateMan);
	DTO_FIELD_INFO(updateMan) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.updateMan");
	}
	// 建立时间
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.createDate");
	}

	// 内部组织机构标识
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.orgId");
	}
	// 岗位类型
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.gwType");
	}

	// 是否临时数据
	DTO_FIELD(String, isTemp);
	DTO_FIELD_INFO(isTemp) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.isTemp");
	}

	// 外部组织机构标识
	DTO_FIELD(String, ormOrgId);
	DTO_FIELD_INFO(ormOrgId) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormOrgId");
	}
	// 组织机构名称(数据库中为ORGNAME,发送数据为ormorgname)
	DTO_FIELD(String, ormOrgName);
	DTO_FIELD_INFO(ormOrgName) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormOrgName");
	}
};

/**
 * 岗位详情分页传输对象
 */
class PostDetailPageDTO : public PageDTO<PostDetailDTO::Wrapper>
{
	DTO_INIT(PostDetailPageDTO, PageDTO<PostDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDETAIL_DTO_