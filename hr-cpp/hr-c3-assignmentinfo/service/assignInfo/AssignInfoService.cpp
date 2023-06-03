#include "stdafx.h"
#include "AssignInfoService.h"
#include "../../dao/assignInfoDAO/AssignInfoDAO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

AssignInfoPageDTO::Wrapper AssignInfoService::listAll(const AssignInfoQuery::Wrapper& query)
{
	//// 构建返回对象
	auto pages = AssignInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	AssignInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AssignInfoDO> result = dao.selectWithPage(query);
	//// 将DO转换成DTO
	for (AssignInfoDO sub : result)
	{
		auto dto = AssignInfoDTO::createShared();
		 	//	dto->id = sub.getId();
		 	//	dto->assign = sub.getAssign();
		 	//	dto->etype = sub.getEtype();
		 	//	dto->organize = sub.getOrganize();
				//dto->depart = sub.getDepart();
				//dto->job = sub.getJob();
				//dto->post= sub.getPost();
				//dto->startTime = sub.getStartTime();
				//dto->endTime = sub.getEndTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,assignId,AssignId ,id, Id,assign,Assign,assignState,AssignState,etype,Etype,organize,Organize,depart,Depart,job,Job,post,Post,startTime,StartTime,endTime,EndTime,createMan,CreateMan,createDate,CreateDate,updateMan,UpdateMan,updateDate,UpdateDate)
			pages->addData(dto);
	}
	return pages;
}

uint64_t AssignInfoService::saveData(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//雪花算法
	SnowFlake c3_assign(1, 3);
	// 组装DO数据
	AssignInfoDO data;
	data.setAssignId(to_string(c3_assign.nextId()));
	//	data.setId(dto->id.getValue(""));
	//	data.setAssign(dto->assign.getValue(""));
	//	data.setEtype(dto->etype.getValue(""));
	   //data.setOrganize(dto->organize.getValue(""));
	   //data.setDepart(dto->depart.getValue(""));
	   //data.setJob(dto->job.getValue(""));
	   //data.setPost(dto->post.getValue(""));
	   //data.setStartTime(dto->startTime.getValue(""));
	   //data.setEndTime(dto->endTime.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Assign, assign, AssignState, assignState, Etype, etype, Organize, organize, Depart, depart, Job, job, Post, post, StartTime, startTime, EndTime, endTime)
	data.setCreateMan(payload.getId());
	SimpleDateTimeFormat time;
	data.setCreateDate(time.format());
	data.setUpdateMan(dto->updateMan.getValue(""));
	data.setUpdateDate(dto->updateDate.getValue(""));
	// 执行数据添加
	AssignInfoDAO dao;
	return dao.insert(data);
}

bool AssignInfoService::updateData(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	AssignInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Assign, assign, AssignState, assignState, Etype, etype, Organize, organize, Depart, depart, Job, job, Post, post, StartTime, startTime, EndTime, endTime, CreateMan, createMan, CreateDate, createDate, UpdateMan, updateMan, UpdateDate, updateDate)
		data.setCreateMan(dto->createMan.getValue(""));
	    data.setCreateDate(dto->createDate.getValue(""));
		SimpleDateTimeFormat time;
		data.setUpdateMan(payload.getId());
		data.setUpdateDate(time.format());
		data.setAssignId(dto->assignId.getValue(""));
		// 执行数据修改
		AssignInfoDAO dao;
	return dao.update(data) == 1;
}

bool AssignInfoService::removeData(string assignId)
{
	AssignInfoDAO dao;
	return dao.deleteById(assignId) == 1;
}

AssignInfoDTO::Wrapper AssignInfoService::QueryDetail(const AssignInfoDTO::Wrapper& dto)
{
	//// 构建返回对象
	//auto page = AssignInfoDTO::createShared();

	//// 将DO转换成DTO
	AssignInfoDAO dao;
	list<AssignInfoDO> result = dao.selectById(dto->assignId);
	for (AssignInfoDO sub : result) {
		//	dto->id = sub.getId();
		//	dto->assign = sub.getAssign();
		//	dto->etype = sub.getEtype();
		//	dto->organize = sub.getOrganize();
			//dto->depart = sub.getDepart();
			//dto->job = sub.getJob();
			//dto->post= sub.getPost();
			//dto->startTime = sub.getStartTime();
			//dto->endTime = sub.getEndTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,assignId,AssignId ,id, Id, assign, Assign,assignState,AssignState, etype, Etype, organize, Organize, depart, Depart, job, Job, post, Post, startTime, StartTime, endTime, EndTime, createMan, CreateMan, createDate, CreateDate, updateMan, UpdateMan, updateDate, UpdateDate)
	}
		return dto;
}
string AssignInfoService::exportData(const AssignExportQuery::Wrapper &query) {
	AssignInfoDAO dao;
	auto result = dao.selectById(query->id.getValue(""));
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("192.168.220.128");
#endif
	vector<vector<std::string>> data;
	for (auto info : result) {
		vector<std::string> row;
		row.emplace_back(info.getAssign());
		row.emplace_back(info.getDepart());
		row.emplace_back(info.getEndTime());
		row.emplace_back(info.getId());
		row.emplace_back(info.getJob());
		row.emplace_back(info.getOrganize());
		row.emplace_back(info.getPost());
		row.emplace_back(info.getStartTime());
		data.emplace_back(std::move(row));
	}
	std::string excel = "./public/excel/assigninfo.xlsx";
	std::string sheet = "AssignInfo";

	ExcelComponent ex;
	ex.writeVectorToFile(excel, sheet, data);

	std::string fieldName = client.uploadFile(excel);
	return client.uploadFile(excel);
}