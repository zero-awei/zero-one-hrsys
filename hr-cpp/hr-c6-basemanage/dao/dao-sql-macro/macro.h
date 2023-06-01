#pragma once
#ifndef _MACRO_H_
#define _MACRO_H_

// 填充string类型字段
// 要求：数据库字段必须与变量字段一致
#define SQLPARAMS_STRING_PUSH(SQL_field) \
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->SQL_field.getValue("")); \
}

// 填充int类型字段
// 要求：数据库字段必须与变量字段一致
#define SQLPARAMS_INT_PUSH(SQL_field)	\
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->SQL_field.getValue(0)); \
}

// 填充double类型字段
// 要求：数据库字段必须与变量字段一致
#define SQLPARAMS_FLOAT_PUSH(SQL_field)		\
if (query->SQL_field) { \
	sql << " AND `" #SQL_field "`=?"; \
	SQLPARAMS_PUSH(params, "d", double, query->SQL_field.getValue(0.0)); \
}

// 填充更新数据字段
#define SQLPARAMS_UPDATE_PUSH(SQL_field)	\
sql << #SQL_field "=?,"

// 填充更新最后一个数据字段
#define SQLPARAMS_UPDATE_PUSH_FINAL(SQL_field, fmt, WHERE_field)	\
sql << #SQL_field "=?";	\
sql << "WHERE "#WHERE_field "=?";	\
fmts << fmt;	\
fmts << "%s"

// 填充INT类型更新字段
#define SQLPARAMS_UPDATE_INT(SQL_field)		\
SQLPARAMS_UPDATE_PUSH(SQL_field);	\
fmts << "%i"

// 填充FLOAT类型更新字段
#define SQLPARAMS_UPDATE_FLOAT(SQL_field)	\
SQLPARAMS_UPDATE_PUSH(SQL_field);	\
fmts << "%d"

// 填充String类型更新字段
#define SQLPARAMS_UPDATE_STRING(SQL_field)		\
SQLPARAMS_UPDATE_PUSH(SQL_field);	\
fmts << "%s"




#endif // !_MACRO_H_