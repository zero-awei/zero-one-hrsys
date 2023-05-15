#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/14 21:08:39

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
#ifndef _WORKHISTORYFINDDTO_H_
#define _WORKHISTORYFINDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistoryFindDTO : public oatpp::DTO
{
public:
	WorkHistoryFindDTO() = default;
	WorkHistoryFindDTO(String servebegintime, String serveendtime, String workunit, \
		String bm, String zw, String gw, String ormrankid, String pimpersonid) : servebegintime(servebegintime), \
		serveendtime(serveendtime), workunit(workunit), bm(bm), zw(zw), gw(gw), ormrankid(ormrankid), \
		pimpersonid(pimpersonid) {}

	DTO_INIT(WorkHistoryFindDTO, DTO);
	
	//1任职开始时间
	DTO_FIELD(String, servebegintime);
	DTO_FIELD_INFO(servebegintime) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.servebegintime");
	}


	//2任职结束时间
	DTO_FIELD(String, serveendtime);
	DTO_FIELD_INFO(serveendtime) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.serveendtime");
	}

	//3工作单位
	DTO_FIELD(String, workunit);
	DTO_FIELD_INFO(workunit) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.workunit");
	}

	//4部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.BM");
	}

	//5职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.zw");
	}

	//6岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.gw");
	}

	//7职级
	DTO_FIELD(String, ormrankid);
	DTO_FIELD_INFO(ormrankid) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.ormrankid");
	}

	//8人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistorypagequery.field.pimpersionid");
	}
};

class WorkHistoryFindPageDTO : public PageDTO<WorkHistoryFindDTO::Wrapper>
{
	DTO_INIT(WorkHistoryFindPageDTO, PageDTO<WorkHistoryFindDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYFINDDTO_H_