#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
 @Date: 2022/10/25 11:08:56

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
#ifndef _EMPLOYEEPAGE_SERVICE_
#define _EMPLOYEEPAGE_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/EmployeePageVO.h"
#include "domain/query/RosterOfPer/EmployeePageQuery.h"
#include "domain/dto/RosterOfPer/EmployeePageDTO.h"
#include "domain/do/RosterOfPer/RosterPersonDO.h"
/*
#define EMPLOYEEPAGE_DTO_TO_DO  ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,\
ormOrgName,ormOrgName,orgsetorName,orgsetorName,ygbh,ygbh,pimpersonName,pimpersonName,\
xb,xb,mz,mz,csrq,csrq,nl,nl,hyzk,hyzk,jg,jg,zzmm,zzmm,rdsj,rdsj,zjhm,zjhm,hkxz,hkxz,\
hjdz,hjdz,sbcjd,sbcjd,dyxl,dyxl,xxlb,xxlb,xxlx,xxlx,dyxlsxzy,dyxlsxzy,dyxlbysj,dyxlbysj,\
dyxlbyyx,dyxlbyyx,zgxlbyyx,zgxlbyyx,zgxl,zgxl,zgxxlb,zgxxlb,zgxllx,zgxllx,zgxljssj,zgxljssj,\
zgxlsxzy,zgxlsxzy,cjgzsj,cjgzsj,gznx,gznx,tozjdate,tozjdate,zjxtgznx,zjxtgznx,dzjbjsj,dzjbjsj,\
bjgznx,bjgznx,dbdwsj,dbdwsj,,pimMajorseTypeName,pimMajorseTypeName,,zw,zw,gw,gw,gwType,gwType,\
jxkhcj,jxkhcj,pimQualTypeName,pimQualTypeName,careerName,careerName,zcbh,zcbh,sfzckjs,sfzckjs,\
zgzsbh,zgzsbh,pimVocationalCatalogName,pimVocationalCatalogName,rzqd,rzqd,htlb,htlb,contractType,\
contractType,qsrq,qsrq,jsrq,jsrq,htsyq,htsyq,htqx,htqx,lxdh,lxdh,yglx,yglx,PCMDETAILID,PCMDETAILID,\
PCMDETAILNAME,PCMDETAILNAME,CREATEMAN,CREATEMAN,,CREATEDATE,CREATEDATE,UPDATEMAN,UPDATEMAN,\
UPDATEDATE,UPDATEDATE,ORMORGID,ORMORGID,ORMORGSECTORID,ORMORGSECTORID,FIRSTEDUCATION,FIRSTEDUCATION,\
SFZGXL,SFZGXL,BZ,BZ,KSTGKMS,KSTGKMS,PX,PX,FIELD,FIELD)
*/
#define EMPLOYEEPAGE_DO_TO_DTO_A ZO_STAR_DOMAIN_DO_TO_DTO(dto , sub, \
ormOrgName, ormOrgName, orgsetorName, orgsetorName, ygbh, ygbh, pimpersonName, pimpersonName, \
xb, xb, mz, mz, csrq, csrq, nl, nl, hyzk, hyzk, jg, jg, zzmm, zzmm, rdsj, rdsj, zjhm, zjhm, hkxz, hkxz, \
hjdz, hjdz, sbcjd, sbcjd, dyxl, dyxl, xxlb, xxlb, xxlx, xxlx, dyxlsxzy, dyxlsxzy, dyxlbysj, dyxlbysj, \
dyxlbyyx, dyxlbyyx, zgxlbyyx, zgxlbyyx, zgxl, zgxl, zgxxlb, zgxxlb, zgxllx, zgxllx, zgxljssj, zgxljssj, \
zgxlsxzy, zgxlsxzy, cjgzsj, cjgzsj, gznx, gznx)

#define EMPLOYEEPAGE_DO_TO_DTO_B ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, \
tozjdate, tozjdate, zjxtgznx, zjxtgznx, dzjbjsj, dzjbjsj, \
bjgznx, bjgznx, dbdwsj, dbdwsj, pimMajorseTypeName, pimMajorseTypeName, zw, zw, gw, gw, gwType, gwType, \
jxkhcj, jxkhcj, pimQualTypeName, pimQualTypeName, careerName, careerName, zcbh, zcbh, sfzckjs, sfzckjs, \
zgzsbh, zgzsbh, pimVocationalCatalogName, pimVocationalCatalogName, rzqd, rzqd, htlb, htlb, contractType, \
contractType, qsrq, qsrq, jsrq, jsrq, htsyq, htsyq, htqx, htqx, lxdh, lxdh, yglx, yglx, PCMDETAILID, PCMDETAILID, \
PCMDETAILNAME, PCMDETAILNAME, CREATEMAN, CREATEMAN, CREATEDATE, CREATEDATE, UPDATEMAN, UPDATEMAN)

#define EMPLOYEEPAGE_DO_TO_DTO_C ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, \
UPDATEDATE, UPDATEDATE, ORMORGID, ORMORGID, ORMORGSECTORID, ORMORGSECTORID, FIRSTEDUCATION, FIRSTEDUCATION, \
SFZGXL, SFZGXL, BZ, BZ, KSTGKMS, KSTGKMS, PX, PX, FIELD, FIELD)

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class EmployeePageService
{
public:
	// 分页查询所有数据
	EmployeePageDTO::Wrapper listAll(const EmployeePageQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_

