#include "stdafx.h"
#include "AddTagController.h"
#include "service/projTag/ProjTagService.h"
#include "SimpleDateTimeFormat.h"
#include "domain/do/projTag/ProjTagDO.h"
StringJsonVO::Wrapper AddTagController::execAddProjTag(const AddProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	// 校验dto数据
	// 参数校验
	// 检验组织标识是否为空
	if (!dto->ormorgid)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	
	// 有效值校验
	
	ProjTagDO data;
	string time = SimpleDateTimeFormat::format();
	string name = payload.getUsername();
	// 设置DO内容
	data.setCreateTime(time);
	data.setUpdateTime(time);
	data.setCreator(name);
	data.setUpdater(name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		TagName, ormxmbqname,
		OrgId, ormorgid);
	// 定义一个service
	ProjTagService service;

	// 执行数据新增 
	// 执行成功后返回项目标签id值
	String id = service.saveData(data);

	//响应结果
	if (id != "-1")
	{
		jvo->init(id, RS_SUCCESS);
	}
	else
	{
		jvo->init(id, RS_FAIL);
	}
	return jvo;
}
