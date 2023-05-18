#include "stdafx.h"
#include "FamilysituationController.h"
#include "../../service/familysituation/FamilysituationService.h"

//FamilysituationPageJsonVO::Wrapper FamilysituationController::execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// 定义一个Service
//	FamilysituationService service;
//	/**************Service***************/
//	//待补充
//	/**************Service***************/
//
//}
//
//Uint64JsonVO::Wrapper FamilysituationController::execAddFamilysituation(const FamilysituationDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	// 非空校验
//	if (!dto->frelationship || !dto->name)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 有效值校验
//	if (dto->name->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	FamilysituationService service;
//	/**************Service***************/
//	//待补充
//	/**************Service***************/
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper FamilysituationController::execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	// 非空校验
//	if (!dto->frelationship || !dto->name)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 有效值校验
//	if (dto->name->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	/**************Service***************/
//	//待补充
//	/**************Service***************/
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper FamilysituationController::execDeleteFamilysituation(const FamilysituationDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	// 非空校验
//	if (!dto->frelationship || !dto->name)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 有效值校验
//	if (dto->name->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	/**************Service***************/
//	//待补充
//	/**************Service***************/
//	return jvo;
//}
//
