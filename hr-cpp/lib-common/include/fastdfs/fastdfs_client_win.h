#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:27:52
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef LINUX
#include <wtypes.h>

#ifndef FASTDFS_CLIENT_WIN_H_
#define FASTDFS_CLIENT_WIN_H_

#define IP_ADDRESS_SIZE				16
#define FDFS_GROUP_NAME_MAX_LEN		16
#define FDFS_FILE_PREFIX_MAX_LEN	16
#define FDFS_GROUP_NAME_MAX_LEN		16
#define FDFS_STORAGE_ID_MAX_SIZE	16
#define FDFS_REMOTE_FILE_NAME_MAX_LEN		128
#define FDFS_FILE_EXT_NAME_MAX_LEN	6
#define FDFS_MAX_SERVERS_EACH_GROUP	32
#define FDFS_MAX_GROUPS				512
#define FDFS_PROTO_PKG_LEN_SIZE		8
#define FDFS_VERSION_SIZE			6
#define FDFS_DOMAIN_NAME_MAX_SIZE	128


typedef enum enumTemplateResult_FDFS
{
	enumSuccess_FDFS = 0,				//成功
	enumFailure_FDFS = 1,				//失败
	enumNotInit_FDFS = 2,				//未初始化
	enumInvalidParameters_FDFS = 3,		//参数错误
	enumNetworkError_FDFS = 4,			//网络错误
	enumFileNotExists_FDFS = 5,			//文件不存在
	enumNoEnoughSpace_FDFS = 6			//磁盘空间不足
} Result_FDFS;

typedef struct __ServerAddress__
{
	TCHAR szIP[16];
	UINT32 nPort;
} ServerAddress;

typedef struct
{
	TCHAR	szGroupName[FDFS_GROUP_NAME_MAX_LEN + 8];	//for 8 bytes alignment
	UINT64	nTotalMB;									//total disk storage in MB
	UINT64	nFreeMB;  //free disk storage in MB
	UINT64	nTrunkFreeMB;  //trunk free disk storage in MB
	UINT32	nCount;        //server count
	UINT32	nStoragePort; //storage server port
	UINT32	nStorageHttpPort; //storage server http port
	UINT32	nActiveCount; //active server count
	UINT32	nCurrentWriteServer; //current server index to upload file
	UINT32	nStorePathCount;  //store base path count of each storage server
	UINT32	nSubdirCountPerPath;
	UINT32	nCurrentTrunkFileID;  //current trunk file id
} FDFSGroupStat;

//FDFS Storage状态数据结构
typedef struct
{
	UINT64 nTotalUploadCount;
	UINT64 nSuccessUploadCount;
	UINT64 nTotalAppendCount;
	UINT64 nSuccessAppendCount;
	UINT64 nTotalModifyCount;
	UINT64 nSuccessModifyCount;
	UINT64 nTotalTruncateCount;
	UINT64 nSuccessTruncateCount;
	UINT64 nTotalSetMetaCount;
	UINT64 nSuccessSetMetaCount;
	UINT64 nTotalDeleteCount;
	UINT64 nSuccessDeleteCount;
	UINT64 nTotalDownloadCount;
	UINT64 nSuccessDownloadCount;
	UINT64 nTotalGetMetaCount;
	UINT64 nSuccessGetMetaCount;
	UINT64 nTotalCreateLinkCount;
	UINT64 nSuccessCreateLinkCount;
	UINT64 nTotalDeleteLinkCount;
	UINT64 nSuccessDeleteLinkCount;
	UINT64 nTotalUploadBytes;
	UINT64 nSuccessUploadBytes;
	UINT64 nTotalAppendBytes;
	UINT64 nSuccessAppendBytes;
	UINT64 nTotalModifyBytes;
	UINT64 nSuccessModifyBytes;
	UINT64 nTotalDownloadBytes;
	UINT64 nSuccessDownloadBytes;
	UINT64 nTotalSyncInBytes;
	UINT64 nSuccessSyncInBytes;
	UINT64 nTotalSyncOutBytes;
	UINT64 nSuccessSyncOutBytes;
	UINT64 nTotalFileOpenCount;
	UINT64 nSuccessFileOpenCount;
	UINT64 nTotalFileReadCount;
	UINT64 nSuccessFileReadCount;
	UINT64 nTotalFileWriteCount;
	UINT64 nSuccessFileWriteCount;

	/* last update timestamp as source server,
		   current server' timestamp
	*/
	time_t lastSourceUpdate;

	/* last update timestamp as dest server,
		   current server' timestamp
	*/
	time_t lastSyncUpdate;

	/* last syned timestamp,
	   source server's timestamp
	*/
	time_t lastSyncedTimestamp;

	/* last heart beat time */
	time_t lastHeartBeatTime;

	struct {
		UINT32 nAllocCount;
		volatile UINT32 nCurrentCount;
		UINT32 nMaxCount;
	} connection;
} FDFSStorageInfo;

typedef struct
{
	BOOL bIfTrunkServer;
	BYTE byStatus;
	TCHAR szID[FDFS_STORAGE_ID_MAX_SIZE];
	TCHAR szIpAddr[IP_ADDRESS_SIZE];
	TCHAR szSrcId[FDFS_STORAGE_ID_MAX_SIZE];
	TCHAR szDomainName[FDFS_DOMAIN_NAME_MAX_SIZE];
	TCHAR szVersion[FDFS_VERSION_SIZE];
	UINT32 nTotalMb;
	UINT32 nFreeMb;
	UINT32 nUploadPriority;
	time_t joinTime;
	time_t upTime;
	UINT32 nStorePathCount;
	UINT32 nSubdirCountPerPath;
	UINT32 nStoragePort;
	UINT32 nStorageHttpPort;
	UINT32 nCurrentWritePath;
	FDFSStorageInfo stat;
} FDFSStorageStat;

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * 初始化FastDFS 客户端
	 *
	 * 参数：
	 * pAddr		[in]	tracker服务器地址数组
	 * nAddrCount	[in]	tracker服务器地址数组的长度，和tracker的数量相同
	 *
	 * 返回值：
	 * enumSuccess_FDFS：初始化成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：初始化失败
	 */
	UINT32 __stdcall FDFSC_Initialize(ServerAddress* pAddr,
		UINT32 nAddrCount,
		UINT32 nLogLevel);

	/**
	 * 反初始化FastDFS 客户端
	 *
	 * 参数：无
	 *
	 * 返回值：无
	 */
	void __stdcall FDFSC_UnInitialize();

	/**
	 * 上传文件
	 *
	 * 参数：
	 * pbyFileBuff			[in]	要上传的文件的内存数据
	 * nFileSize			[in]	要上传的文件的大小
	 * pszFileExtName		[in]	要上传的文件的扩展名
	 * pszGroupName			[out]   上传的文件所在组的组名
	 * pszRemoteFileName	[out]	上传的文件文件名
	 *
	 * 返回值：
	 * enumSuccess_FDFS：上传成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：上传失败
	 */
	UINT32 __stdcall FDFSC_UploadFile(const BYTE* pbyFileBuff, UINT32 nFileSize, const TCHAR* pszFileExtName,
		TCHAR* pszGroupName, TCHAR* pszRemoteFileName);

	/**
	 * 上传文件
	 *
	 * 参数：
	 * pbyFileBuff			[in]	要上传的文件的内存数据
	 * nFileSize			[in]	要上传的文件的大小
	 * pszFileExtName		[in]	要上传的文件的扩展名
	 * pszFileID			[out]	上传的文件ID
	 *
	 * 返回值：
	 * enumSuccess_FDFS：上传成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：上传失败
	 */
	UINT32 __stdcall FDFSC_UploadFileByID(const BYTE* pbyFileBuff, UINT32 nFileSize, const TCHAR* pszFileExtName,
		TCHAR* pszFileID);

	/**
	 * 上传从文件
	 *
	 * 参数：
	 * pbyFileBuff			[in]	要上传的从文件的内存数据
	 * nFileSize			[in]	要上传的从文件的大小
	 * pszMasterGroupName	[in]	主文件所在组的组名
	 * pszMasterFileName	[in]	主文件的文件名
	 * pszPrefixName		[in]	从文件的Prefix
	 * pszFileExtName		[in]	要上传的从文件的扩展名
	 * pszGroupName			[out]   上传的从文件所在组的组名
	 * pszRemoteFileName	[out]	上传的从文件文件名
	 *
	 * 返回值：
	 * enumSuccess_FDFS：上传成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：上传失败
	 */
	UINT32 __stdcall FDFSC_UploadSlaveFile(const BYTE* pbyFileBuff, UINT32 nFileSize,
		const TCHAR* pszMasterGroupName, const TCHAR* pszMasterFileName,
		const TCHAR* pszPrefixName, const TCHAR* pszFileExtName,
		TCHAR* pszGroupName, TCHAR* pszRemoteFileName);

	/**
	 * 上传从文件
	 *
	 * 参数：
	 * pbyFileBuff			[in]	要上传的从文件的内存数据
	 * nFileSize			[in]	要上传的从文件的大小
	 * pszMasterGroupName	[in]	主文件所在组的组名
	 * pszMasterFileName	[in]	主文件的文件名
	 * pszPrefixName		[in]	从文件的Prefix
	 * pszFileExtName		[in]	要上传的从文件的扩展名
	 * pszFileID			[out]	上传的从文件ID
	 *
	 * 返回值：
	 * enumSuccess_FDFS：上传成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：上传失败
	 */
	UINT32 __stdcall FDFSC_UploadSlaveFileByID(const BYTE* pbyFileBuff, UINT32 nFileSize,
		const TCHAR* pszMasterGroupName, const TCHAR* pszMasterFileName,
		const TCHAR* pszPrefixName, const TCHAR* pszFileExtName,
		TCHAR* pszFileID);

	/**
	 * 下载文件
	 *
	 * 参数：
	 * pszGroupName			[in]	要下载的文件所在组的组名
	 * pszRemoteFileName	[in]	要下载的文件的文件名
	 * pbyFileBuff			[out]	下载的文件地址
	 * nFileSize			[out]	下载的文件大小
	 *
	 * 返回值：
	 * enumSuccess_FDFS：下载成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：下载失败
	 */
	UINT32 __stdcall FDFSC_DownloadFile(const TCHAR* pszGroupName, const TCHAR* pszRemoteFileName,
		BYTE* pbyFileBuff, UINT32* nFileSize);

	/**
	 * 下载文件
	 *
	 * 参数：
	 * pszFileID			[in]	要下载的文件的ID
	 * pbyFileBuff			[out]	下载的文件地址
	 * nFileSize			[out]	下载的文件大小
	 *
	 * 返回值：
	 * enumSuccess_FDFS：下载成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：下载失败
	 */
	UINT32 __stdcall FDFSC_DownloadFileByID(const TCHAR* pszFileID,
		BYTE* pbyFileBuff, UINT32* nFileSize);

	/**
	 * 下载文件
	 *
	 * 参数：
	 * pszTrackerIPList		[in]	Tracker的IP列表
	 * pszFileID			[in]	要下载的文件的ID
	 * pbyFileBuff			[out]	下载的文件地址
	 * nFileSize			[out]	下载的文件大小
	 *
	 * 返回值：
	 * enumSuccess_FDFS：下载成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：下载失败
	 *
	 * 备注
	 * 未初始化就可以调用
	 */
	UINT32 __stdcall FDFSC_DownloadFileByIDEx(const TCHAR* pszTrackerIPList, const TCHAR* pszFileID,
		BYTE* pbyFileBuff, UINT32* nFileSize);

	/**
	 * 删除文件
	 *
	 * 参数：
	 * pszGroupName			[in]	要删除的文件所在组的组名
	 * pszRemoteFileName	[in]	要删除的文件的文件名
	 *
	 * 返回值：
	 * enumSuccess_FDFS：删除成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：删除失败
	 */
	UINT32 __stdcall FDFSC_DeleteFile(const TCHAR* pszGroupName, const TCHAR* pszRemoteFileName);

	/**
	 * 删除文件
	 *
	 * 参数：
	 * pszFileID			[in]	要删除的文件ID
	 *
	 * 返回值：
	 * enumSuccess_FDFS：删除成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：删除失败
	 */
	UINT32 __stdcall FDFSC_DeleteFileByID(const TCHAR* pszFileID);

	/**
	 * 删除文件
	 *
	 * 参数：
	 * pszTrackerIPList		[in]	制定Tracker的IP地址列表
	 * pszFileID			[in]	要删除的文件ID
	 *
	 * 返回值：
	 * enumSuccess_FDFS：删除成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：删除失败
	 *
	 * 备注
	 * 未初始化就可以调用
	 */
	UINT32 __stdcall FDFSC_DeleteFileByIDEx(const TCHAR* pszTrackerIPList, const TCHAR* pszFileID);

	/**
	 * 查询Group信息
	 *
	 * 参数：
	 * pTrackerAddr			[in]	查询的Tracker服务器地址
	 * pStat				[in,out]	FDFSGroupStat结构体数组用于返回查询结果
	 * nLen					[in]	数组长度,取FDFS_MAX_GROUPS即可
	 * pnStatCount			[out]	用于返回查询结果的FDFSGroupStat数量
	 *
	 * 返回值：
	 * enumSuccess_FDFS：查询成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：查询失败
	 * enumNetworkError_FDFS：网络错误
	 * enumNotInit_FDFS：未初始化成功
	 */
	UINT32 __stdcall FDFSC_TrackerListGroups(ServerAddress* pTrackerAddr, FDFSGroupStat* pStat, UINT32 nLen, UINT32* pnStatCount);

	/**
	 * 查询Group内Storage服务器信息
	 *
	 * 参数：
	 * pTrackerAddr			[in]	查询的Tracker服务器地址
	 * pszGroupName			[in]	查询的组名
	 * pStat				[in,out]	FDFSGroupStat结构体数组用于返回查询结果
	 * nLen					[in]	数组长度为FDFS_MAX_GROUPS
	 * pnStatCount			[out]	用于返回查询结果的FDFSGroupStat数量
	 *
	 * 返回值：
	 * enumSuccess_FDFS：查询成功
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：查询失败
	 * enumNetworkError_FDFS：网络错误
	 * enumNotInit_FDFS：未初始化成功
	 */
	UINT32 __stdcall FDFSC_TrackerListStorages(ServerAddress* pTrackerAddr, TCHAR* pszGroupName, FDFSStorageStat* pStat, UINT32 nLen, UINT32* pnStatCount);

	/**
	 * 检查同组的Tracker获取到的Storage是否相同
	 *
	 * 参数：
	 * pszTrackerIPList		[in]	制定Tracker的IP地址列表
	 *
	 * 返回值：
	 * enumSuccess_FDFS：配置相同
	 * enumInvalidParameters_FDFS：无效的参数
	 * enumFailure_FDFS：检查失败
	 *
	 * 备注
	 * 未初始化就可以调用
	 */
	UINT32 __stdcall FDFSC_CheckConfiguration(const TCHAR* pszTrackerIPList);

#ifdef __cplusplus
}
#endif

#endif
#endif