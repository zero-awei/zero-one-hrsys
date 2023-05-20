#include "stdafx.h"
#include "ContractController.h"


ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// ������Ӧ����
	auto vo = ContractJsonVO_::createShared();
	// ��Ӧ���
	//vo->success(1);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ��Ӧ���
	//jvo->success(1);
	return jvo;
}

StringJsonVO::Wrapper ContractController::execUploadContract(const String& fileBody, const String& suffix)
{
	auto vo = StringJsonVO::createShared();
	//vo->success(String(ss.str().c_str()));
	return vo;
}

StringJsonVO::Wrapper ContractController::execDownloadContract(const ContractDownloadQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();

	// TODO: ����service��ȡ�����ļ���������

	vo->success("url/download");
	return vo;
}
