/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "OrgService.h"
#include "tree/TreeUtil.h"
#include "service/org/TreeOrgMapper.h"
#include <iostream>

// 查询部门结构树
vector<shared_ptr<OrgTreeDTO>> OrgService::getOrgTree(const string& userID) {
	OrgDAO orgDao;
	list<OrgTreeDO> top = orgDao.selectRootOrg(userID);
	list<OrgTreeDO> mid;
	list<OrgTreeDO> bottom;
	for (const auto &org : top) {
		mid.splice(mid.end(), orgDao.selectValidOrg(org.getOrgID()));
	}
	for (const auto& org : mid) {
		bottom.splice(bottom.end(), orgDao.selectOrgSector(org.getOrgID()));
	}

	// for (const auto& org : top) {
	// 	std::cout << org.getOrgType() << " " << org.getOrgID() << " " << org.getOrgName() << " " << org.getPorgID() << std::endl;
	// }
	// for (const auto& org : mid) {
	// 	std::cout << org.getOrgType() << " " << org.getOrgID() << " " << org.getOrgName() << " " << org.getPorgID() << std::endl;
	// }
	// for (const auto& org : bottom) {
	// 	std::cout << org.getOrgType() << " " << org.getOrgID() << " " << org.getOrgName() << " " << org.getPorgID() << std::endl;
	// }
	// std::cout << "top: " << top.size() << std::endl;
	// std::cout << "mid: " << mid.size() << std::endl;
	// std::cout << "bot: " << bottom.size() << std::endl;

	// transform to make tree
	for (auto &org : top) {
		org.setPorgID(std::string(""));
	}
	top.splice(top.end(), mid);
	top.splice(top.end(), bottom);

	// 转换为树形结构
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<OrgTreeDO>(top, TreeOrgMapper());
	// std::cout << "res: " << res.size() << std::endl;
	vector<shared_ptr<OrgTreeDTO>> v;
	for (const auto &one : res)
	{
		// vo->data->push_back(MenuDTO::Wrapper(dynamic_pointer_cast<MenuDTO>(one), MenuDTO::Wrapper::Class::getType()));
		v.emplace_back(dynamic_pointer_cast<OrgTreeDTO>(one));
	}

	return v;
}