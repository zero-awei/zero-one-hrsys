#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2023/02/17 16:29:07

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
#ifndef _TREEORG_MAPPER_H
#define _TREEORG_MAPPER_H

#include "tree/TreeNodeMapper.h"
#include "domain/do/org/OrgTreeDO.h"
#include "domain/dto/org/OrgTreeDTO.h"

/**
 * 演示菜单数据字段匹配实现
 */
class TreeOrgMapper : public TreeNodeMapper<OrgTreeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(OrgTreeDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<OrgTreeDTO>();
		// 计算层级结构属性映射
		res->_id(source->getOrgID());
		res->_pid(source->getPorgID());
		// 扩展属性映射
		res->orgtype = source->getOrgType();
		res->orgname = source->getOrgName();
		res->orgid = source->getOrgID();
		return res;
	}
};

#endif // !_TREEORG_MAPPER_H