#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/13 14:50:35

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
#ifndef _TREENODE_H_
#define _TREENODE_H_
#include <string>
#include <list>
#include <memory>
using namespace std;
/**
 * 用来定义一个树形节点的数据
 */
class TreeNode
{
private:
	/**
	 * 节点ID
	 */
	string __id;
	/**
	 * 节点父节点ID
	 */
	string __pid;
	/**
	 * 节点深度
	 */
	int __depth;
	/**
	 * 节点包含的子节点
	 */
	list<shared_ptr<TreeNode>> __children;
public:
	// 添加子节点，如果子类需要管理添加子节点操作可以通过重写此函数实现
	virtual void addChild(shared_ptr<TreeNode> child)
	{
		__children.push_back(child);
	}
	// 初始化构造
	TreeNode()
	{
		_id("");
		_pid("");
		_depth(0);
	}
	// getter / setter
	std::string _id() const { return __id; }
	void _id(std::string val) { __id = val; }
	std::string _pid() const { return __pid; }
	void _pid(std::string val) { __pid = val; }
	int _depth() const { return __depth; }
	void _depth(int val) { __depth = val; }
	const list<shared_ptr<TreeNode>>* _children() { return &__children; }
};

#endif // !_TREENODE_H_