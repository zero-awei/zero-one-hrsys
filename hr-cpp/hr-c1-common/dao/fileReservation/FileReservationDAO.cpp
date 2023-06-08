
#include "stdafx.h"
#include "FileReservationDAO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
std::list<FileReservationDO> FileReservationDAO::selectFileReservationList()
{
	std::list<FileReservationDO> res;
	FileReservationDO data;
	data.setFileReservation(ZH_WORDS_GETTER("fileReservation.localbase"));
	data.setCode(10);
	res.push_back(data);
	data.setFileReservation(ZH_WORDS_GETTER("fileReservation.enterbase"));
	data.setCode(20);
	res.push_back(data);
	data.setFileReservation(ZH_WORDS_GETTER("fileReservation.other"));
	data.setCode(30);
	res.push_back(data);
	return res;
}
