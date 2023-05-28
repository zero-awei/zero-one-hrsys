#include "stdafx.h"
#include "ContractController.h"


ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// ������Ӧ����
	auto vo = ContractJsonVO_::createShared();

	auto data = ContractDTO_::createShared();
	// �ǿ�У��
	if (!query->PIMCONTRACTID)
	{
		vo->init(data, RS_PARAMS_INVALID);
		return vo;
	}

	// ��Ӧ���
	vo->success(data);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// �ǿ�У��
	if (!dto->PIMCONTRACTID || !dto->CREATEMAN || !dto->CREATEDATE || !dto->UPDATEDATE || !dto->PIMCONTRACTNAME)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ��Ӧ���
	jvo->success(1);
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



	// У��
	if (query->sequence != "ASC" && query->sequence != "DESC")
	{
		vo->init("error(please contact akie)", RS_PARAMS_INVALID);
		return vo;
	}

	vo->success("url/download");
	return vo;
}
