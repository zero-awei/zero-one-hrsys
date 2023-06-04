#pragma once
/*
* （人员花名册 - 人员花名册 - 分页查询员工数据）--洛洛
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

class EmployeePageService
{
public:
	// 分页查询所有数据
	EmployeePageDTO::Wrapper listAll(const EmployeePageQuery::Wrapper& query);

};

#endif // !_EMPLOYEEPAGE_SERVICE_

