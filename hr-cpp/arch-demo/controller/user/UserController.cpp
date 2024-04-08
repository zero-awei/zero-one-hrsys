/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/20 16:29:31

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
#include "UserController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "FastDfsClient.h"
#include "domain/do/user/MenuDO.h"
#include "service/user/TreeMenuMapper.h"
#include "tree/TreeUtil.h"

/**
 * 注意：这里的部分代码本应该放到service层中，为了方便演示就写在一起了
 */

UserPageJsonVO::Wrapper UserController::executeQueryAll(const UserQuery::Wrapper& query)
{
	// 定义一个JsonVO对象
	auto vo = UserPageJsonVO::createShared();
	// 定义一个分页对象
	auto page = UserPageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	page->total = 20;
	page->calcPages();

	// 模拟计算分页数据
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);//与sql 语句 select * from 表名 limit (页码数-1) * 记录数 有着 映射关系
	int64_t end = start + page->pageSize.getValue(1);
	// 边界值值处理
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// 循环生成测试数据
	for (int64_t i = start; i < end; i++)
	{
		auto user = UserDTO::createShared();
		user->nickname = query->nickname;
		user->age = (uint32_t)(i + 1) * 10;
		user->idCard = "12345678901234567" + oatpp::utils::conversion::uint64ToStdStr(i);
		page->addData(user);
	}
	vo->success(page);
	return vo;
}

StringJsonVO::Wrapper UserController::executePostFile(const String& fileBody, const String& suffix)
{
	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/file/";

	// 计算时间戳
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// 获取毫秒
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// 拼接后缀名
	ss << suffix.getValue("");

	// 临时文件名称
	std::string fileName = ss.str();
	// 保存文件到临时目录
	fileBody.saveToFile(fileName.c_str());

	// 测试上传到FastDFS文件服务器
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("192.168.144.33");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://192.168.144.33:8888/" << fieldName;
	// 创建响应数据
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}

MenuJsonVO::Wrapper UserController::executeQueryMenu(const PayloadDTO& payload)
{
	// 定义一个JsonVO对象
	auto vo = MenuJsonVO::createShared();
	// 创建模拟菜单数据（此数据应来源于数据库）
	list<MenuDO> listData;
	listData.push_back(MenuDO("1", u8"系统管理", "sm", "/sm", ""));
	listData.push_back(MenuDO("2", u8"用户管理", "sm", "/sm/um", "1"));
	listData.push_back(MenuDO("3", u8"角色管理", "sm", "/sm/rm", "1"));
	listData.push_back(MenuDO("4", u8"菜单管理", "sm", "/sm/mm", "1"));
	listData.push_back(MenuDO("5", u8"订单管理", "om", "/om", ""));
	listData.push_back(MenuDO("6", u8"入库订单", "om", "/om/em", "5"));
	listData.push_back(MenuDO("7", u8"出库订单", "om", "/om/om", "5"));
	listData.push_back(MenuDO("8", u8"销售订单", "om", "/om/sm", "5"));
	listData.push_back(MenuDO("9", u8"订单统计", "om", "/om/sm/t1", "8"));
	listData.push_back(MenuDO("10",u8"订单报表", "om", "/om/sm/t2", "8"));
	// 转换为树形结构
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<MenuDO>(listData, TreeMenuMapper());
	// 将根节点存储到列表中
	for (auto one : res)
	{
		vo->data->push_back(MenuDTO::Wrapper(dynamic_pointer_cast<MenuDTO>(one), MenuDTO::Wrapper::Class::getType()));
	}
	return vo;
}
