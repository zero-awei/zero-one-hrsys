#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55

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
#ifndef _PROJTAGSERVICE_H_
#define _PROJTAGSERVICE_H_
#include "domain/dto/projTag/ProjTagDTO.h"
#include "domain/dto/projTag/OrgListDTO.h"
#include "domain/query/projTag/OrgListQuery.h"
#include "domain/query/projTag/PageProjTagQuery.h"
#include "domain/dto/projTag/ModifyTagDTO.h"
#include "domain/vo/projTag/ProjTagVO.h"
#include "domain/dto/projTag/ImportTagDTO.h"
#include "domain/vo/projTag/ImportTagVO.h"
#include "domain/query/projTag/ExportProjTagQuery.h"
#include "domain/do/projTag/ProjTagDO.h"
/**
 * 项目标签Service
 */
class ProjTagService
{
public:
	/**
	 * 新增项目标签
	 * 返回值：
	 *	成功：项目标签id
	 *  失败：-1
	 * 负责人：远翔
	 */
	string saveData(ProjTagDO& data);
	/**
	 * 分页查询组织列表
	 * 负责人：Andrew
	 */
	OrgListPageDTO::Wrapper listOrgList(const OrgListQuery::Wrapper &query);
	/**
	 * 修改项目标签
	 * 负责人：Andrew
	 */
	bool updateProjTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload);

	/**
	 * 导入项目标签：数据量超过5000时，只导入<=5000条数据
	 * 返回值：
	 *	成功：返回项目id列表
	 *  失败: -2，数据不符合数据库限制
	 * 负责人：远翔
	 */
	ImportTagVO::Wrapper addMultiTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload);
	/**
	 * 导出项目标签（最大5000条）
	 * 调用DAO查询数据库，返回后包装进Excel文件并保存到FastDFS文件服务器
	 * 返回值：文件服务器拼接下载链接
	 * 负责人：Andrew
	 */
	std::string exportProjTag(const ExportProjTagQuery::Wrapper& query);
	/**
	 * 分页查询项目标签
	 * 负责人：咫尺之书
	 */
	ProjTagPageDTO::Wrapper listProjTagList(const PageProjTagQuery::Wrapper& query);
};

#endif // !_PROJTAGSERVICE_H_
