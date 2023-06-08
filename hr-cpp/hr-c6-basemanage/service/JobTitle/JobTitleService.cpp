#include "stdafx.h"
#include "JobTitleService.h"
#include "./dao/JobTitle/JobTitleDAO.h"
#include "Macros.h"
#include "SnowFlake.h"
#include "FastDfsClient.h"

JobTitlePageDTO::Wrapper JobTitleService::listAll(const JobTitleQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = JobTitlePageDTO::createShared();
	pages->pageIndex = query->pageIndex;   // 页面索引 
	pages->pageSize = query->pageSize;     // 页面大小

	// 创建dao对象
	JobTitleDAO dao;
	// 查询数据条数
	uint64_t count = dao.count(query);
	cout << "总条数为：" << count << endl;
	if (count <= 0) {
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages(); // 计算总页数

	// 获取数据
	std::list<JobTitleDO> result = dao.selectAll(query);

	// 将DO转换成DTO
	for (JobTitleDO r : result) {
		auto dto = JobTitleDTO::createShared();
		// 将DO转换为DTO
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, r, id, Id, employee_id, Employee_Id
			, employee_name, Employee_Name, employee_state, Employee_State,
			org_name, Org_Name, jobtitle_name, Jobtitle_Name,
			get_time, Get_Time, certificate_id, Certificate_Id,
			professional_cate, Professional_Cate,
			employment_month, Employment_Month,
			jobtitle_grades, Jobtitle_Grades,
			title_employment_time, Title_Employment_Time,
			issuing_authority, Issuing_Authority,
			judging_unit, Judging_Unit,
			b_highest_professional_title, B_Highest_Professional_Title
		);
		// 将每条数据加入到结果对象中
		pages->addData(dto);
	}
	return pages;
}

JobTitlePageDTO::Wrapper JobTitleService::listByParams(const JobTitleQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = JobTitlePageDTO::createShared();
	pages->pageIndex = query->pageIndex;   // 页面索引 
	pages->pageSize = query->pageSize;     // 页面大小

	// 创建dao对象
	JobTitleDAO dao;
	// 查询数据条数
	uint64_t count = dao.count(query);
	cout << "总条数为：" << count << endl;
	if (count <= 0) {
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages(); // 计算总页数

	// 获取数据
	std::list<JobTitleDO> result = dao.selectAll(query);

	// 将DO转换成DTO
	for (JobTitleDO r : result) {
		auto dto = JobTitleDTO::createShared();
		// 将DO转换为DTO
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, r, id, Id, employee_id, Employee_Id
			, employee_name, Employee_Name, employee_state, Employee_State,
			org_name, Org_Name, jobtitle_name, Jobtitle_Name,
			get_time, Get_Time, certificate_id, Certificate_Id,
			professional_cate, Professional_Cate,
			employment_month, Employment_Month,
			jobtitle_grades, Jobtitle_Grades,
			title_employment_time, Title_Employment_Time,
			issuing_authority, Issuing_Authority,
			judging_unit, Judging_Unit,
			b_highest_professional_title, B_Highest_Professional_Title
		);
		// 将每条数据加入到结果对象中
		pages->addData(dto);
	}
	return pages;
}

uint64_t JobTitleService::addData(const JobTitleAddDTO::Wrapper& dto)
{
	// 组装DO数据
	JobTitleAddDO data;
	// 定义dao
	JobTitleDAO dao;
	// 使用雪花算法生成唯一id
	SnowFlake sf(1, 1);
	string id = std::to_string(sf.nextId());
	cout << id << endl;
	data.setId(id);
	data.setEmployee_Id(dto->employee_id.getValue(""));
	data.setEmployee_Name(dto->employee_name.getValue(""));
	data.setJobtitle_Name(dto->jobtitle_name.getValue(""));
	data.setGet_Time(dto->get_time.getValue(""));
	data.setCertificate_Id(dto->certificate_id.getValue(""));
	data.setJobtitle_Grades(dto->jobtitle_grades.getValue(""));
	data.setProfessional_Cate(dto->professional_cate.getValue(""));
	data.setProfessional_Name(dto->professional_name.getValue(""));
	data.setIssuing_Authority(dto->issuing_authority.getValue(""));
	data.setJudging_Unit(dto->judging_unit.getValue(""));
	data.setTitle_Employment_Time(dto->title_employment_time.getValue(""));
	data.setB_Highest_Professional_Title(dto->b_highest_professional_title.getValue(""));
	data.setAttachment(dto->attachment.getValue(""));
	// 通过employee_id 和employee_name 获取pimpersonid
	list<JobTitleAddDO> result = dao.getPinpersonid(data);
	if (!result.empty()) {
		// 在id和name的固定下结果唯一
		JobTitleAddDO r = result.back();
		data.setPimperson_Id(r.getPimperson_Id());
	}
	else {
		// 找不到对应人员信息返回操作失败
		return uint64_t(0);
	}
	cout << "获取的人员信息id为：" << data.getPimperson_Id() << endl;
	return dao.addTitle(data);
}

uint64_t JobTitleService::removeData(const JobTitleDeleteDTO::Wrapper& dto)
{
	JobTitleDAO dao;
	return dao.removeById(dto);
}

String JobTitleService::postFile(const String& fileBody, const String& suffix)
{
	// 根据时间生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/file/";
	// 计算时间戳
	auto now = std::chrono::system_clock::now();   // 获取当前时间
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");

	// 获取毫秒
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// 拼接后缀名
	ss << suffix.getValue("");
	// 临时文件名称
	std::string fileName = ss.str();
	//std::string fileName = "D:/文件/Slide.pdf";
	cout << "文件名：" << fileName << endl;
	// 保存文件到临时目录
	fileBody.saveToFile(fileName.c_str());

	// 测试上传FastDFS文件服务器
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif

	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15/" << fieldName;
	return String(ss.str().c_str());
}
