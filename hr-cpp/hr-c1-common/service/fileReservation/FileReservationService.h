#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/30 0:18:19

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
#ifndef _FILERESERVATIONSERVICE_H_
#define _FILERESERVATIONSERVICE_H_
#include "domain/dto/pullList/PullListDTO.h"
#include "uselib/pullListRedis/UseLibRedis.h"
/**
 * 档案保管地Service
 * 负责人：远翔
 */
class FileReservationService
{
public:
	// 查询下拉列表数据
	PullListDTO::Wrapper listAll();
};



#endif // !_FILERESERVATIONSERVICE_H_