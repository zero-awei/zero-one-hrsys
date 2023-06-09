#include "stdafx.h"
#include "AssignInfoService.h"
#include "../../dao/assignInfoDAO/AssignInfoDAO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

// 文件到DO宏
#define FILE_TO_DO(target, src, f1, f2) target.set##f1(src.f2);
#define INDEX(x, y) at(x).at(y)
#define ZO_STAR_FILE_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, FILE_TO_DO, __VA_ARGS__))

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
		auto dto = AssignInfoQueryDTO::createShared();
		//	dto->id = sub.getId();
		//	dto->assign = sub.getAssign();
		//	dto->etype = sub.getEtype();
		//	dto->organize = sub.getOrganize();
			//dto->depart = sub.getDepart();
			//dto->job = sub.getJob();
			//dto->post= sub.getPost();
			//dto->startTime = sub.getStartTime();
			//dto->endTime = sub.getEndTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, assignId, AssignId, id, Id, assign, Assign, assignState, AssignState, etype, Etype, organize, Organize, depart, Depart, job, Job, post, Post, startTime, StartTime, endTime, EndTime, createMan, CreateMan, createDate, CreateDate, updateMan, UpdateMan, updateDate, UpdateDate)
			pages->addData(dto);
	}
	return pages;
}

uint64_t AssignInfoService::saveData(const AssignInfoCommonDTO::Wrapper& dto, const PayloadDTO& payload)
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
	// 执行数据添加
	AssignInfoDAO dao;
	return dao.insert(data);
}

bool AssignInfoService::updateData(const AssignInfoCommonDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	AssignInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Assign, assign, AssignState, assignState, Etype, etype, Organize, organize, Depart, depart, Job, job, Post, post, StartTime, startTime, EndTime, endTime)
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

AssignInfoQueryDTO::Wrapper AssignInfoService::QueryDetail(const AssignInfoQueryDTO::Wrapper& dto)
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
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, assignId, AssignId, id, Id, assign, Assign, assignState, AssignState, etype, Etype, organize, Organize, depart, Depart, job, Job, post, Post, startTime, StartTime, endTime, EndTime, createMan, CreateMan, createDate, CreateDate, updateMan, UpdateMan, updateDate, UpdateDate)
	}
	return dto;
}


//导入员工信息(批量新增)
ImportInfoJsonVO::Wrapper AssignInfoService::addMultiAssignInfo(const ImportAssignInfoDTO::Wrapper& dto, const PayloadDTO& payload) {

	// 构建Excel对象
	ExcelComponent excel;
	// 将文件数据读取出来
	auto data = excel.readIntoVector(std::string(dto->filePath), std::string(dto->sheetName));

	// 构建字段坐标映射
	unordered_map<string, int> hash;
	for (size_t i = 0; i < data[0].size(); i++)
	{
		hash[data[0][i]] = i;
	}

	// 生成SnowFlake对象
	SnowFlake sf(1, 3);//雪花算法
	string name = payload.getId();
	string day = SimpleDateTimeFormat::format();//获取当前时间格式字符串
	// 文件数据到DO
	list<AssignInfoDO> all;
	for (size_t i = 1; i < data.size(); i++)
	{
		AssignInfoDO tmp;
		ZO_STAR_FILE_TO_DO(tmp, data,
			Id, INDEX(i, hash["ID"]),
			Assign, INDEX(i, hash["ASSIGN"]),
			AssignState, INDEX(i, hash["ASSIGNSTATE"]),
			Etype, INDEX(i, hash["ETYPE"]),
			Organize, INDEX(i, hash["ORGANIZE"]),
			Depart, INDEX(i, hash["DEPART"]),
			Job, INDEX(i, hash["JOB"]),
			Post, INDEX(i, hash["POST"]),
			StartTime, INDEX(i, hash["STARTTIME"]),
			EndTime, INDEX(i, hash["ENDTIME"])
		);
		//生成主键
		tmp.setAssignId(to_string(sf.nextId()));
		//建立人
		tmp.setCreateMan(name);
		//建立时间
		tmp.setCreateDate(day);
		all.push_back(tmp);
	}

	// 调用DAO操作数据库
	AssignInfoDAO dao;
	SqlSession* ss = dao.getSqlSession();
	// 开启事务处理
	ss->beginTransaction();

	std::list<std::string> res;
	for (auto item : all)
	{
		auto line = dao.insert(item);
		// 新增成功则加入一个新的id
		if (line == 1)
		{
			res.push_back(item.getAssignId());
		}
		// 否则清空新增id返回列表并回滚
		else
		{
			ss->rollbackTransaction();
			res.clear();
			break;
		}
	}

	// 提交事务
	ss->commitTransaction();

	// 构建返回对象
	auto vo = ImportInfoJsonVO::createShared();
	//if (res.size())
	//{
	//	for (auto item : res)
	//		vo->newId->push_back(item);
	//}

	return vo;
}

bool AssignInfoService::removeMulData(const MulDeleteAssignInfoDTO::Wrapper& dto)
{
	AssignInfoDAO dao;
	auto sqlSession = dao.getSqlSession();
	sqlSession->beginTransaction();
	bool isSuccess = true;
	for (const auto& item : *dto->assignIds) {
		if (dao.deleteById(item->c_str()) != 1)
		{
			sqlSession->rollbackTransaction();
			isSuccess = false;
			return isSuccess;
		}
	}
	sqlSession->commitTransaction();
	return isSuccess;
}

string AssignInfoService::exportData(const AssignExportQuery::Wrapper& query) {
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