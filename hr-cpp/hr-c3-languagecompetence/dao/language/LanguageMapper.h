#pragma once
#ifndef _LANGUAGE_MAPPER_
#define _LANGUAGE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/language/LanguageDO.h"

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
		data.setLanguageAbilityID(resultSet->getString(1));
		data.setPermission(resultSet->getInt(2));
		data.setGainTime(resultSet->getString(3));
		data.setAttachment(resultSet->getString(4));
		data.setLanguageType(resultSet->getString(5));
		data.setCreateMan(resultSet->getString(6));
		data.setUpdateMan(resultSet->getString(7));
		data.setLanguageLevel(resultSet->getString(8));
		data.setPersonID(resultSet->getString(9));
		data.setJLSS(resultSet->getString(10));
		data.setJLGLBH(resultSet->getString(11));
		data.setJLSPZT(resultSet->getString(12));
		data.setJLCZZ(resultSet->getString(13));
		return data;
	}
};

#endif // !_LANGUAGE_MAPPER