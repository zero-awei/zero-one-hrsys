/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/20 20:24:59
*/
#ifndef _EDUCATIONIMPORTDTO_H_
#define _EDUCATIONIMPORTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationImportDTO : public oatpp::DTO
{
	DTO_INIT(EducationImportDTO, DTO);
	// 文件类型
	DTO_FIELD_INFO(fileType) {
		info->description = ZH_WORDS_GETTER("importEducation.fileType");
	}
	DTO_FIELD(String, fileType);
	// 数据表名
	DTO_FIELD_INFO(sheetName) {
		info->description = ZH_WORDS_GETTER("importEducation.sheetName");
	}
	DTO_FIELD(String, sheetName);
	// 文件路径(后端产生)
	DTO_FIELD(String, filePath);
	DTO_FIELD(Vector<Vector<String>>, fileData);

public:
	EducationImportDTO()
	{
		fileType = "xlsx";
		filePath = "";
	}

	EducationImportDTO(String type, String name, String path)
	{
		fileType = type;
		sheetName = name;
		filePath = path;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONIMPORTDTO_H_