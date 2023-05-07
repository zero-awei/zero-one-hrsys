#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/13 15:09:41

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
#ifndef _TREEUTIL_H_
#define _TREEUTIL_H_
#include "TreeNode.h"
#include "TreeNodeMapper.h"

class TreeUtil
{
private:
	static void findChildNodes(TreeNode* parentNode, list<shared_ptr<TreeNode>>* nodes)
	{
		for (shared_ptr<TreeNode> child : *nodes) {
			// 找到父节点的子节点
			if (parentNode->_id() == child->_pid()) {
				// 设置子节点的相关层次数据
				child->_depth(parentNode->_depth() + 1);
				// 将子节点添加到父节点的子节点集合中
				parentNode->addChild(child);
				// 查找子节点包含的子节点
				findChildNodes(child.get(), nodes);
			}
		}
	}
public:
	//************************************
	// Method:    listToTree
	// FullName:  TreeUtil::listToTree
	// Access:    public static 
	// Returns:   返回转换后的数据
	// Qualifier: 将行数据转换成树形数据
	// Parameter: const list<T> & dataList 待转换的行数据
	// Parameter: const M & mapper 行数据与节点数据字段匹配器
	//************************************
	template<typename T, typename M = TreeNodeMapper<T>>
	static list<shared_ptr<TreeNode>> listToTree(const list<T>& dataList, const M& mapper)
	{
		// 把集合中的数据转换为节点数据
		list<shared_ptr<TreeNode>> nodes;
		for (T row : dataList) {
			shared_ptr<TreeNode> node = mapper.objectMapper(&row);
			nodes.push_back(node);
		}
		// 构建一个具有层次结构的树
		list<shared_ptr<TreeNode>> tree;
		// 循环获取根节点
		for (shared_ptr<TreeNode> node : nodes) {
			if ("" == node->_pid()) {
				node->_depth(0);
				tree.push_back(node);
				// 查找子节点
				findChildNodes(node.get(), &nodes);
			}
		}
		return tree;
	}
};

#endif // !_TREEUTIL_H_