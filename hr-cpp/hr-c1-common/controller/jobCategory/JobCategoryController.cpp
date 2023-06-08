//﻿/*
// Copyright Zero One Star. All rights reserved.
//
// @Author: Andrew211vibe
// @Date: 2023/05/18 22:51:37
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	  https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*/
#include"stdafx.h"
#include"JobCategoryController.h"
#include "service/jobCategory/JobCategoryService.h"
PullListVO::Wrapper JobCategoryController::execQueryJobCategory()
{
	auto vo = PullListVO::createShared();
	/*auto dto = PullListDTO::createShared();
	dto->pullList->push_back(ItemDTO::createShared(1, u8"房屋建筑类"));
	dto->pullList->push_back(ItemDTO::createShared(2, u8"基础设施类"));
	dto->pullList->push_back(ItemDTO::createShared(3, u8"金融投资类"));
	dto->pullList->push_back(ItemDTO::createShared(4, u8"勘察设计类"));
	dto->pullList->push_back(ItemDTO::createShared(5, u8"职能管理类"));*/

	// TODO:调用service返回PullListDTO
	JobCategoryService service;
	auto dto = service.listAll();

	vo->success(dto);
	return vo;
}