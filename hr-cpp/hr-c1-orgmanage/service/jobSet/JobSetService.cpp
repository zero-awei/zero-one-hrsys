
#include "stdafx.h"
#include "JobSetService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "SqlSession.h"
#include "TransactionManager.h"
#include "domain/do/postSet/PostDetailDO.h"
#include "dao/jobSet/JobSetDAO.h"
std::list<string> JobSetService::saveMultiJob(const ImportJobDTO::Wrapper& dto)
{
	
	// Excel组件
	std::string fileName = dto->filePath;
	std::string sheetName = dto->sheetName;
	ExcelComponent excel;
	
	// 保存从文件中读取的数据
	auto data = excel.readIntoVector(fileName, sheetName);

	// 判断当前数据规模能否一次导入
	

	// 所有数据的汇总
	list<PostDetailDO> dataList;
	for (auto row : data)
	{
		// 定义一个岗位设置DO，即PostDetailDO
		PostDetailDO dataSingle;
		int i = 0;
		for (auto cellval : row)
		{	
			// 用序号直接对应到某一列，写死
			switch (i) {
			case 0:
				dataSingle.setOrmPostId(cellval);
				break;
			case 1:
				dataSingle.setOrgId(cellval);
				break;
			case 2: 
				dataSingle.setOrmOrgName(cellval);
				break;
			case 3:
				dataSingle.setGwfl(cellval);
				break;
			case 4:
				dataSingle.setIsConfidential(cellval);
				break;
			case 5:
				dataSingle.setPostNature(cellval);
				break;
			case 6:
				dataSingle.setIsKeyPostion(cellval);
				break;
			case 7:
				dataSingle.setStartStopSign(cellval);
				break;
			}
			i++;
		}
		dataList.push_back(dataSingle);
	}

	JobSetDAO dao;
	return dao.insertMultiData(dataList);
}
