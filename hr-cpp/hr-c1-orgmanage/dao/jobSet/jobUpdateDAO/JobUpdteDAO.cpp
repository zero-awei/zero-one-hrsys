#include "stdafx.h"
#include "JobUpdteDAO.h"

#define JOBSET_TERAM_PARSE(__DO__, __SQL__) \
SqlParams params; \
if (__DO__.getOrmPostName() != "") { \
	__SQL__ << " `ORMPOSTNAME`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getOrmPostName()); \
} \
if (__DO__.getIsKeyPostion() != "") { \
	__SQL__ << " `ISKEYPOSTION`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getIsKeyPostion()); \
} \
if (__DO__.getOrmOrgId() != "") { \
	__SQL__ << " `ORMORGID`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getOrmOrgId()); \
} \
if (__DO__.getGwType() != "") { \
	__SQL__ << " `GWTYPE`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getGwType()); \
} \
if (__DO__.getGwfl() != "") { \
	__SQL__ << " `GWFL`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getGwfl()); \
} \
if (__DO__.getIsConfidential() != "") { \
	__SQL__ << " `ISCONFIDENTIAL`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getIsConfidential()); \
} \
if (__DO__.getIsTemp() != "") { \
	__SQL__ << " `ISTEMP`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getIsTemp()); \
} \
if (__DO__.getPostNature() != "") { \
	__SQL__ << " `POSTNATURE`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getPostNature()); \
} \
if (__DO__.getStartStopSign() != "") { \
	__SQL__ << " `STARTSTOPSIGN`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getStartStopSign()); \
} \
if (__DO__.getNx() != 0) { \
	__SQL__ << " `NX`=?,"; \
	SQLPARAMS_PUSH(params, "ui", uint32_t, __DO__.getNx()); \
} \
if (__DO__.getBxjlnx() != 0) { \
	__SQL__ << " `BXJLNX`=?,"; \
	SQLPARAMS_PUSH(params, "ui", uint32_t, __DO__.getBxjlnx()); \
}

bool JobUpdteDAO::updateJob(const PostDetailDO& data)
{
	stringstream sql;
	sql << "UPDATE `t_ormpost` SET ";
	JOBSET_TERAM_PARSE(data, sql);
	sql << " `UPDATEDATE`=?, `UPDATEMAN`=? WHERE `ORMPOSTID`=?";
	SQLPARAMS_PUSH(params, "s", std::string, data.getUpdateDate());
	SQLPARAMS_PUSH(params, "s", std::string, data.getUpdateMan());
	SQLPARAMS_PUSH(params, "s", std::string, data.getOrmPostId());

	string mysql = sql.str();
	return sqlSession->executeUpdate(mysql, params);
}
