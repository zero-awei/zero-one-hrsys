#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/21 16:57:23

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
#ifndef _POSTDETAIL_DO_
#define _POSTDETAIL_DO_
#include "../DoInclude.h"

/**
 * 岗位设置 - 查询指定岗位详情DO
 */
class PostDetailDO
{
	// 排序标号*
	CC_SYNTHESIZE(uint32_t, xh,Xh);
	// 岗位分类*
	CC_SYNTHESIZE(string, gwfl, Gwfl);
	// 是否保密岗*
	CC_SYNTHESIZE(string, isConfidential, IsConfidential);
	// 岗位集名称*
	CC_SYNTHESIZE(string, ormPostName, OrmPostName);
	// 建议交流年限*
	CC_SYNTHESIZE(uint32_t, nx,Nx);
	// 必须交流年限*
	CC_SYNTHESIZE(uint32_t, bxjlnx, Bxjlnx);
	// 是否关键岗位*
	CC_SYNTHESIZE(string, isKeyPostion, IsKeyPostion);
	// 岗位性质*
	CC_SYNTHESIZE(string, postNature, PostNature);
	// 启用标识*
	CC_SYNTHESIZE(string, startStopSign, StartStopSign);
	// 岗位集标识
	CC_SYNTHESIZE(string, ormPostId, OrmPostId);
	// 建立人
	CC_SYNTHESIZE(string, createMan, CreateMan);
	// 更新时间
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	// 更新人
	CC_SYNTHESIZE(string, updateMan, UpdateMan);
	// 建立时间
	CC_SYNTHESIZE(string, createDate, CreateDate);
	// 内部组织机构标识
	CC_SYNTHESIZE(string, orgId, OrgId);
	// 岗位类型
	CC_SYNTHESIZE(string, gwType, GwType);
	// 是否临时数据
	CC_SYNTHESIZE(string, isTemp, IsTemp);
	// 外部组织机构标识
	CC_SYNTHESIZE(string, ormOrgId, OrmOrgId);
	// 组织机构名称(数据库中为ORGNAME,发送数据为ormorgname)
	CC_SYNTHESIZE(string, ormOrgName, OrmOrgName);
public:
	PostDetailDO() {
		xh = 0;
		gwfl = "";
		isConfidential = "";
		ormPostName = "";
		nx = 0;
		bxjlnx = 0;
		isKeyPostion = "";
		postNature = "";
		startStopSign = "";
		ormPostId = "";
		createMan = "";
		updateDate = "";
		updateMan = "";
		createDate = "";
		orgId = "";
		gwType = "";
		isTemp = "";
		ormOrgId = "";
		ormOrgName = "";
	}
};

#endif // !_POSTDETAIL_DO_
