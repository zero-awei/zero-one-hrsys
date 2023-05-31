//2023年5月23日
//创建档案保管地DO
//作者：狗皮电耗子
#pragma once
#ifndef _PIM_ARCHIVES_DO_
#define _PIM_ARCHIVES_DO_
#include "../DoInclude.h"
class PimArchivesDO
{
	CC_SYNTHESIZE(string, pimarchivesID, PimArchivesID);
	CC_SYNTHESIZE(string, pimarchivesName, PimArchivesName);
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	CC_SYNTHESIZE(string, creatorName, CreateName);
	CC_SYNTHESIZE(string, createDate, CreateDate);
	CC_SYNTHESIZE(string, updaterName, UpdaterName);
	CC_SYNTHESIZE(string, archivesNo, ArchivesNo);
	CC_SYNTHESIZE(string, archivesState, ArchivesState);
	CC_SYNTHESIZE(string, archivesAddr, ArchivesAddr);
	CC_SYNTHESIZE(string, dispatchDate, DispatchDate);
	CC_SYNTHESIZE(string, dispatchOutDate, DispatchOutDate);
	CC_SYNTHESIZE(string, dispatchInAddr, DispatchInAddr);
	CC_SYNTHESIZE(string, dispatchOutAddr, DispatchOutAddr);
	CC_SYNTHESIZE(string, saveNo, SaveNo);
	CC_SYNTHESIZE(string, note, Note);
	CC_SYNTHESIZE(string, pimpersonID, PimPersonID);
	CC_SYNTHESIZE(string, ormorgID, OrmorgID);
	CC_SYNTHESIZE(string, ormorgID2, OrmorgID2);
	CC_SYNTHESIZE(string, attachment, Attachment);
	CC_SYNTHESIZE(string, dateOfBirth, DateOfBirth);
	CC_SYNTHESIZE(string, startWorkDate, StartWorkDate);
	CC_SYNTHESIZE(string, joinPartyDate, JoinPartyDate);
	CC_SYNTHESIZE(string, education, Education);
	CC_SYNTHESIZE(string, damu, DAMU);
	CC_SYNTHESIZE(string, custodyNow, CustodyNow);
	CC_SYNTHESIZE(string, ormorgID3, OrmorgID3);
	CC_SYNTHESIZE(string, ormorgName, OrmorgName);
	CC_SYNTHESIZE(string, state, State);
	CC_SYNTHESIZE(string, archivesCenterID, ArchivesCenterID);
	CC_SYNTHESIZE(string, operattions, Operattions);
	CC_SYNTHESIZE(string, operattionsDate, OperattionsDate);
	CC_SYNTHESIZE(string, transToOut, TransToOut);
	CC_SYNTHESIZE(string, ormorgName2, OrmorgName2);
	CC_SYNTHESIZE(string, source, Source);
	CC_SYNTHESIZE(string, save, Save);
	CC_SYNTHESIZE(string, archivesState, ArchivesState);
	CC_SYNTHESIZE(string, calloutArchives, CalloutArchives);
	CC_SYNTHESIZE(string, callinArchives, CallinArchives);
public:
	PimArchivesDO() {
		pimarchivesID = "档案信息标识";
		pimarchivesName = "档案信息名称";
		updateDate = "更新时间";
		creatorName = "建立人";
		createDate = "建立时间";
		updaterName = "更新人";
		archivesNo = "档案编号";
		archivesState = "档案状态";
		archivesAddr = "档案保管地";
		dispatchDate = "档案调动日期";
		dispatchOutDate = "档案调出日期";
		dispatchInAddr = "档案调入单位";
		dispatchOutAddr = "档案调出单位";
		saveNo = "存放柜号";
		note = "备注";
		pimpersonID = "员工";
		ormorgID = "组织标识";
		ormorgID2 = "现档案保管单位标识";
		attachment = "附件";
		dateOfBirth = "档案出生日期";
		startWorkDate = "档案参加工作时间";
		joinPartyDate = "档案入党时间";
		education = "档案学历";
		damu = "档案目录";
		custodyNow = "现档案保管单位";
		ormorgID3 = "管理单位";
		ormorgName = "所属单位";
		state = "档案借阅状态";
		archivesCenterID = "档案室管理标识";
		operattions = "操作内容";
		operattionsDate = "操作时间";
		transToOut = "调出至（外单位）";
		ormorgName2 = "调出单位";
		source = "档案来源地";
		save = "档案保管地";
		archivesState = "档案状态";
		calloutArchives = "调出档案";
		callinArchives = "调入档案";
	}
};


#endif // !_PIM_ARCHIVES_DO_
