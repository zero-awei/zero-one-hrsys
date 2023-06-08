#pragma once
/*
（人员花名册-人员花名册-分页查询员工数据）--洛洛
*/
#ifndef _EMPLOYEEPAGE_MAPPER_
#define _EMPLOYEEPAGE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/RosterPersonDO.h"

class EmployeePageMapper : public Mapper<RosterPersonDO>
{
public:
	RosterPersonDO mapper(ResultSet* resultSet) const override
	{
		RosterPersonDO data;

		data.setPCMDETAILID(resultSet->getString(1));
		data.setPCMDETAILNAME(resultSet->getString(2));
		data.setCREATEMAN(resultSet->getString(3));
		data.setCREATEDATE(resultSet->getString(4));
		data.setUPDATEMAN(resultSet->getString(5));
		data.setUPDATEDATE(resultSet->getString(6));
		data.setORMORGID(resultSet->getString(7));
		data.setygbh(resultSet->getString(8));
		data.setxb(resultSet->getString(9));
		data.setmz(resultSet->getString(10));
		data.setzjhm(resultSet->getString(11));
		data.setjg(resultSet->getString(12));
		data.sethyzk(resultSet->getString(13));
		data.setcsrq(resultSet->getString(14));
		data.setzzmm(resultSet->getString(15));
		data.setrdsj(resultSet->getString(16));
		data.setormOrgName(resultSet->getString(17));
		data.setgw(resultSet->getString(18));
		data.setpimMajorseTypeName(resultSet->getString(19));
		data.setORMORGSECTORID(resultSet->getString(20));
		data.setpimpersonName(resultSet->getString(21));
		data.sethjdz(resultSet->getString(22));
		data.sethkxz(resultSet->getString(23));
		data.setzw(resultSet->getString(24));
		data.setcareerName(resultSet->getString(25));
		data.setgwType(resultSet->getString(26));
		data.setpimVocationalCatalogName(resultSet->getString(27));
		data.setpimQualTypeName(resultSet->getString(28));
		data.setsbcjd(resultSet->getString(29));
		data.setFIRSTEDUCATION(resultSet->getInt(30));
		data.setdyxlbyyx(resultSet->getString(31));
		data.setdyxlsxzy(resultSet->getString(32));
		data.setxxlb(resultSet->getString(33));
		data.setSFZGXL(resultSet->getInt(34));
		data.setzgxlbyyx(resultSet->getString(35));
		data.setzgxlsxzy(resultSet->getString(36));
		data.setzgxljssj(resultSet->getString(37));
		data.setcontractType(resultSet->getString(38));
		data.setqsrq(resultSet->getString(39));
		data.setjsrq(resultSet->getString(40));
		data.sethtsyq(resultSet->getString(41));
		data.setrzqd(resultSet->getString(42));
		data.setlxdh(resultSet->getString(43));
		data.setyglx(resultSet->getString(44));
		data.setjxkhcj(resultSet->getString(45));
		data.setBZ(resultSet->getString(46));
		data.setzcbh(resultSet->getString(47));
		data.setKSTGKMS(resultSet->getString(48));
		data.setPX(resultSet->getString(49));
		data.setsfzckjs(resultSet->getInt(50));
		data.settozjdate(resultSet->getString(51));
		data.setgznx(resultSet->getInt(52));
		data.setbjgznx(resultSet->getString(53));
		data.setdzjbjsj(resultSet->getString(54));
		data.setdbdwsj(resultSet->getString(55));
		data.setzgzsbh(resultSet->getInt(56));
		data.setcjgzsj(resultSet->getString(57));
		data.setFIELD(resultSet->getString(58));
		data.setzgxxlb(resultSet->getString(59));
		data.setzgxllx(resultSet->getString(60));
		data.setdyxl(resultSet->getString(61));
		data.setzgxl(resultSet->getString(62));
		data.sethtlb(resultSet->getString(63));




		/*
		data.setormOrgName(resultSe7647t->getString(1));
		data.setorgsetorName(result48Set->getString(2));
		data.setygbh(resultSet->get49String(3));
		data.setpimpersonName(resul50tSet->getString(4));
		data.setxb(resultSet->getSt51ring(5));
		data.setmz(resultSet->getSt52ring(6));
		data.setcsrq(resultSet->get53String(7));
		data.setnl(resultSet->getIn54t(8));
		data.sethyzk(resultSet->get55String(9));
		data.setjg(resultSet->getSt56ring(10));
		data.setzzmm(resultSet->get57String(11));
		data.setrdsj(resultSet->get58String(12));
		data.setzjhm(resultSet->get59String(13));
		data.sethkxz(resultSet->get60String(14));
		data.sethjdz(resultSet->get61String(15));
		data.setsbcjd(resultSet->ge62tString(16));
		data.setdyxl(resultSet->get63String(17));
		data.setxxlb(resultSet->get64String(18));
		data.setxxlx(resultSet->get65String(19));
		data.setdyxlsxzy(resultSet - 66 > getString(20));
		data.setdyxlbysj(resultSet - 67 > getString(21));
		data.setdyxlbyyx(resultSet - 68 > getString(22));
		data.setzgxlbyyx(resultSet - 69 > getString(23));
		data.setzgxl(resultSet->get70String(24));
		data.setzgxxlb(resultSet->g71etString(25));
		data.setzgxllx(resultSet->g72etString(26));
		data.setzgxljssj(resultSet - 73 > getString(27));
		data.setzgxlsxzy(resultSet - 74 > getString(28));
		data.setcjgzsj(resultSet->g75etString(29));
		data.setgznx(resultSet->get76Int(30));
		data.settozjdate(resultSet->getString(31));
		data.setzjxtgznx(resultSet->getInt(32));
		data.setdzjbjsj(resultSet->getString(33));
		data.setbjgznx(resultSet->getString(34));
		data.setdbdwsj(resultSet->getString(35));
		data.setbdwgznx(resultSet->getString(36));
		data.setpimMajorseTypeName(resultSet->getString(37));
		data.setrank(resultSet->getString(38));
		data.setzw(resultSet->getString(39));
		data.setgw(resultSet->getString(40));
		data.setgwType(resultSet->getString(41));
		data.setjxkhcj(resultSet->getString(42));
		data.setpimQualTypeName(resultSet->getString(43));
		data.setcareerName(resultSet->getString(44));
		data.setzcbh(resultSet->getString(45));
		data.setsfzckjs(resultSet->getInt(46));
		data.setzgzsbh(resultSet->getInt(47));
		data.setpimVocationalCatalogName(resultSet->getString(48));
		data.setrzqd(resultSet->getString(49));
		data.sethtlb(resultSet->getString(50));
		data.setcontractType(resultSet->getString(51));
		data.setqsrq(resultSet->getString(52));
		data.setjsrq(resultSet->getString(53));
		data.sethtsyq(resultSet->getString(54));
		data.sethtqx(resultSet->getString(55));
		data.setlxdh(resultSet->getString(56));
		data.setyglx(resultSet->getString(57));
		data.setPCMDETAILID(resultSet->getString(58));
		data.setPCMDETAILNAME(resultSet->getString(59));
		data.setCREATEMAN(resultSet->getString(60));
		data.setENABLE(resultSet->getInt(61));
		data.setCREATEDATE(resultSet->getString(62));
		data.setUPDATEMAN(resultSet->getString(63));
		data.setUPDATEDATE(resultSet->getString(64));
		data.setORMORGID(resultSet->getString(65));
		data.setORMORGSECTORID(resultSet->getString(66));
		data.setFIRSTEDUCATION(resultSet->getInt(67));
		data.setSFZGXL(resultSet->getInt(68));
		data.setBZ(resultSet->getString(69));
		data.setKSTGKMS(resultSet->getString(70));
		data.setPX(resultSet->getString(71));
		data.setFIELD(resultSet->getString(72));
		*/

		return data;
	}								 
};

#endif // !_EMPLOYEEPAGE_MAPPER_