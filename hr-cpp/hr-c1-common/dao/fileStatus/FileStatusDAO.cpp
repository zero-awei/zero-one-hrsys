
#include "stdafx.h"
#include "FileStatusDAO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
std::list<FileStatusDO> FileStatusDAO::selectFileStatusList()
{
	std::list<FileStatusDO> res;
	FileStatusDO data;
	data.setFileStatus(ZH_WORDS_GETTER("fileStatus.borrowing"));
	data.setCode(10);
	res.push_back(data);
	data.setFileStatus(ZH_WORDS_GETTER("fileStatus.returned"));
	data.setCode(20);
	res.push_back(data);
	return res;
}
