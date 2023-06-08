#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/16 22:14:51

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
#ifndef _IMPORTJOBDTO_H_
#define _IMPORTJOBDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 岗位设置 - 导入岗位DTO
 * 负责人：Andrew
 */
class ImportJobDTO : public oatpp::DTO
{
	DTO_INIT(ImportJobDTO, DTO);
	// 文件类型
	DTO_FIELD_INFO(fileType) {
		info->description = ZH_WORDS_GETTER("jobSet.import.fileType");
	}
	DTO_FIELD(String, fileType);
	// 数据表名
	DTO_FIELD_INFO(sheetName) {
		info->description = ZH_WORDS_GETTER("jobSet.import.sheetName");
	}
	DTO_FIELD(String, sheetName);
	// 文件路径(后端产生)
	DTO_FIELD(String, filePath);
	DTO_FIELD(Vector<Vector<String>>, fileData);

public:
	ImportJobDTO()
	{
		fileType = "xlsx";
		filePath = "";
		sheetName = "";
	}

	ImportJobDTO(String type, String name, String path)
	{
		fileType = type;
		sheetName = name;
		filePath = path;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTJOBDTO_H_