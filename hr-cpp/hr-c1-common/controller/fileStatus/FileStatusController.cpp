/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/17 16:46:06

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
#include "FileStatusController.h"

PullListVO::Wrapper FileStatusController::execQueryFileStatus()
{
	auto dto = PullListDTO::createShared();
	auto borrowing = ItemDTO::createShared(1, ZH_WORDS_GETTER("fileStatus.borrowing"));
	dto->pullList->push_back(borrowing);
	auto returned = ItemDTO::createShared(2, ZH_WORDS_GETTER("fileStatus.returned"));
	dto->pullList->push_back(returned);
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
