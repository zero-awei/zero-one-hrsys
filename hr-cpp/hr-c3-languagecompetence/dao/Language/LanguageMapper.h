#pragma once
#ifndef _LANGUAGE_MAPPER_
#define _LANGUAGE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Language/LanguageDO.h"

/**
 * 语言能力字段匹配映射
 * 负责人： 君
 */
class LanguageMapper : public Mapper<LanguageDO> 
{
public:
	LanguageDO mapper(ResultSet* resultSet) const override 
	{
		LanguageDO data;
		data.setPermission(resultSet->getInt(1));
		data.setGainTime(resultSet->getString(2));
		data.setAttachment(resultSet->getString(3));
		data.setLanguageType(resultSet->getString(4));
		data.setCreateMan(resultSet->getString(5));
		data.setUpdateMan(resultSet->getString(6));
		data.setLanguageLevel(resultSet->getString(7));
		data.setPersonID(resultSet->getString(8));
		data.setJLSS(resultSet->getString(9));
		data.setJLGLBH(resultSet->getString(10));
		data.setJLSPZT(resultSet->getString(11));
		data.setJLCZZ(resultSet->getString(12));
		return data;
	}
};

#endif // !_LANGUAGE_MAPPER