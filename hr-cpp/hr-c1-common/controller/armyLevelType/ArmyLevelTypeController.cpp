/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/18 22:51:37

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
#include "ArmyLevelTypeController.h"
#include "service/armyLevelType/ArmyLevelTypeService.h"

PullListVO::Wrapper ArmyLevelTypeController::execQueryArmyLevelType()
{
	auto vo = PullListVO::createShared();

	// 示例返回
	/*auto dto = PullListDTO::createShared();
	dto->pullList->push_back(ItemDTO::createShared(1, u8"正营职"));
	dto->pullList->push_back(ItemDTO::createShared(2, u8"正排职"));
	dto->pullList->push_back(ItemDTO::createShared(3, u8"副团职"));
	dto->pullList->push_back(ItemDTO::createShared(4, u8"副连职"));*/

	// TODO:调用service返回PullListDTO
	ArmyLevelTypeService service;
	auto dto = service.listAll();

	vo->success(dto);
	return vo;
}
