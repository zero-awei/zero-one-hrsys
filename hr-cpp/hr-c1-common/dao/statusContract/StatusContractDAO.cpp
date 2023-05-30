
#include "stdafx.h"
#include "StatusContractDAO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
std::list<ConstractStatusDO> StatusContractDAO::selectConstractStatusList()
{
	std::list<ConstractStatusDO> res;
	ConstractStatusDO data;
	data.setConstractStatus(ZH_WORDS_GETTER("contractStatus.duration"));
	data.setCode(20);
	res.push_back(data);
	data.setConstractStatus(ZH_WORDS_GETTER("contractStatus.outOfDate"));
	data.setCode(30);
	res.push_back(data);
	data.setConstractStatus(ZH_WORDS_GETTER("contractStatus.haveSigned"));
	data.setCode(40);
	res.push_back(data);
	data.setConstractStatus(ZH_WORDS_GETTER("contractStatus.terminated"));
	data.setCode(50);
	res.push_back(data);
	return res;
}
