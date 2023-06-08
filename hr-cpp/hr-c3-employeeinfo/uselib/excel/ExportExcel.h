#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/06/08 14:58:41

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
#ifndef _EXPORTEXCEL_H_
#define _EXPORTEXCEL_H_

#include <string>
#include <vector>

/**
 * Excel 组件, 用于导出数据
 */
class ExportExcel
{
public:
	static std::string exportExcel(const std::vector<std::vector<std::string>>& data);
};

#endif // _EXPORTEXCEL_H_