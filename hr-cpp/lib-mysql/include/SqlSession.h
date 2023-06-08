#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:51:22
 
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
#ifndef _SQL_SESSION_
#define _SQL_SESSION_
#include <stdarg.h>
#include <vector>
#include "DbInit.h"
#include "Mapper.h"
#include "TryCatchFinally.h"

#ifdef LINUX
#include <string.h>
#define ARG_B(__args__) static_cast<bool>(va_arg(__args__, int))
#define ARG_S(__args__) va_arg(__args__, std::string)
#define SCPY(de, len, sr) snprintf(de, len, "%s", sr.c_str());
#define STOK strtok_r
#else
#define ARG_B(__args__) va_arg(__args__, bool)
#define ARG_S(__args__) va_arg(__args__, std::string)
#define SCPY(de, len, sr) strcpy_s(de, len, sr.c_str());
#define STOK strtok_s
#endif

#define SQL_PARAM_SETTING1(__tag__, __args__, __pos__, __pstmt__) \
if (__tag__ == "cs") __pstmt__->setString(__pos__, va_arg(__args__, char*)); \
else if (__tag__ == "s") __pstmt__->setString(__pos__, ARG_S(__args__)); \
else if (__tag__ == "i") __pstmt__->setInt(__pos__, va_arg(__args__, int32_t)); \
else if (__tag__ == "ui") __pstmt__->setUInt(__pos__, va_arg(__args__, uint32_t)); \
else if (__tag__ == "ll") __pstmt__->setInt64(__pos__, va_arg(__args__, int64_t)); \
else if (__tag__ == "ull") __pstmt__->setUInt64(__pos__, va_arg(__args__, uint64_t)); \
else if (__tag__ == "bi") __pstmt__->setBigInt(__pos__, ARG_S(__args__)); \
else if (__tag__ == "nul") __pstmt__->setNull(__pos__, va_arg(__args__, int)); \
else if (__tag__ == "b") __pstmt__->setBoolean(__pos__, ARG_B(__args__)); \
else if (__tag__ == "d") __pstmt__->setDouble(__pos__, va_arg(__args__, double)); \
else if (__tag__ == "dt") __pstmt__->setDateTime(__pos__, ARG_S(__args__)); \
else __pstmt__->setString(__pos__, ARG_S(__args__)); 

#define SQL_PARAM_SETTING2(__tag__, __pos__, __pstmt__,__val_var__) \
if (__tag__ == "s") __pstmt__->setString(__pos__, *static_cast<std::string*>(__val_var__)); \
else if (__tag__ == "i") __pstmt__->setInt(__pos__, *static_cast<int32_t*>(__val_var__)); \
else if (__tag__ == "ui") __pstmt__->setUInt(__pos__, *static_cast<uint32_t*>(__val_var__)); \
else if (__tag__ == "ll") __pstmt__->setInt64(__pos__, *static_cast<int64_t*>(__val_var__)); \
else if (__tag__ == "ull") __pstmt__->setUInt64(__pos__, *static_cast<uint64_t*>(__val_var__)); \
else if (__tag__ == "bi") __pstmt__->setBigInt(__pos__, *static_cast<std::string*>(__val_var__)); \
else if (__tag__ == "nul") __pstmt__->setNull(__pos__, *static_cast<int*>(__val_var__)); \
else if (__tag__ == "b") __pstmt__->setBoolean(__pos__, *static_cast<bool*>(__val_var__)); \
else if (__tag__ == "d") __pstmt__->setDouble(__pos__, *static_cast<double*>(__val_var__)); \
else if (__tag__ == "dt") __pstmt__->setDateTime(__pos__, *static_cast<std::string*>(__val_var__)); \
else __pstmt__->setString(__pos__, *static_cast<std::string*>(__val_var__)); 

#define SQL_ARG_EXEC_1(__pstmt__, __fmt__, __args__) \
if (__fmt__ != "") { \
	while (__fmt__.find_first_of("%") == 0) { \
		__fmt__ = __fmt__.substr(1); \
	} \
	size_t len = __fmt__.length() + 1; \
	char* strs = new char[len]; \
	SCPY(strs, len, __fmt__); \
	char* next; \
	char* p = STOK(strs, "%", &next); \
	int pos = 1; \
	while (p) { \
		string tag(p); \
		SQL_PARAM_SETTING1(tag, __args__, pos, __pstmt__); \
		p = STOK(NULL, "%", &next); \
		pos++; \
	} \
	delete[] strs; \
}

#define SQL_ARG_EXEC_2(__pstmt__, __fmt__) \
va_list __args__; \
va_start(__args__, __fmt__); \
std::string __curr_fmt__(__fmt__); \
SQL_ARG_EXEC_1(__pstmt__, __curr_fmt__, __args__); \
va_end(__args__); 

#define SQL_ARG_EXEC_3(__params__, __pstmt__) \
if (!__params__.empty()) { \
	int pos = 1; \
	for (auto one : __params__) { \
		SQL_PARAM_SETTING2(one.key, pos, __pstmt__, one.value.get()); \
		pos++; \
	} \
}

#define RELEASE_SQL_OBJECT(obj, funName) \
if (obj) { \
	try \
	{ \
		obj->close(); \
	} \
	catch (const std::exception& e) \
	{ \
		cerr<<funName<<" Exception. "<<e.what()<<endl; \
	} \
	delete obj; \
	obj = NULL; \
}

// 定义一个空指针检查宏，为空指针是抛出异常
#define NULL_PTR_CHECK(__ptr__, __message__) \
if (!__ptr__) { \
	throw std::runtime_error(__message__); \
}

/**
 * 定义一个SQL填充参数对象
 */
class SqlParam
{
public:
	SqlParam(std::string key, shared_ptr<void> value) {
		this->key = key;
		this->value = value;
	}
	// 数据类型占位符
	std::string key;
	// 对应的数据
	shared_ptr<void> value;
};
// 定义一个SQL填充参数数据集类型
typedef std::vector<SqlParam> SqlParams;
// 定义一个SQL填充参数数据集添加数据宏
#define SQLPARAMS_PUSH(__PARAMS__, __PARAM_KEY__, __VAL_TYPE__, __VAL_VAL__) \
__PARAMS__.emplace_back(SqlParam(__PARAM_KEY__, std::make_shared<__VAL_TYPE__>(__VAL_VAL__)))

/**
 * 定义一个数据库操作工具类
 * 参考链接：https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-apps.html
 */
class SqlSession final
{
private:
	// 数据库连接对象
	Connection* conn;
	// PreparedStatement对象
	PreparedStatement* pstmt;
	// Statement对象
	Statement* stmt;
	// 结果集对象
	ResultSet* res;
	// 释放PreparedStatement对象
	void releasePreparedStatement();
	// 释放Statement对象
	void releaseStatement();
	// 释放结果集对象
	void releaseResultSet();
	// 执行数据更新操作
	int update(const string& sql, const char* fmt, va_list args);
public:
	SqlSession();
	~SqlSession();

	//************************************
	// Method:    execute
	// FullName:  SqlSession::execute
	// Access:    public 
	// Returns:   bool
	// Qualifier: 执行SQL语句，一般用于DDL
	// Parameter: const string & sql SQL语句
	//************************************
	bool execute(const string& sql);
	
	//************************************
	// Method:    executeUpdate
	// FullName:  SqlSession::executeUpdate
	// Access:    public 
	// Returns:   int 影响数据行数
	// Qualifier: 更新数据，一般用于DML
	// Parameter: const string & sql sql语句
	// Parameter: const char* fmt 可变参数格式字符串,如:%s%i%bi%b%d%dt%n
	// Parameter: ... 可变参数
	//************************************
	int executeUpdate(const string& sql, const char* fmt, ...);

	//************************************
	// Method:    executeUpdate
	// FullName:  SqlSession::executeUpdate
	// Access:    public 
	// Returns:   int 影响数据行数
	// Qualifier: 更新数据，一般用于DML
	// Parameter: const string & sql sql语句
	//************************************
	int executeUpdate(const string& sql);

	//************************************
	// Method:    executeUpdate
	// FullName:  SqlSession::executeUpdate
	// Access:    public 
	// Returns:   int 影响数据行数
	// Qualifier: 更新数据，一般用DML
	// Parameter: const string & sql sql语句
	// Parameter: const SqlParams & params SQL语句填充参数
	//************************************
	int executeUpdate(const string& sql, const SqlParams& params);

	//************************************
	// Method:    executeInsert
	// FullName:  SqlSession::executeInsert
	// Access:    public 
	// Returns:   uint64_t 自动增长ID值
	// Qualifier: 插入数据，用于数据库主键自增的数据表，主键非自增请使用executeUpdate
	// Parameter: const string & sql sql语句
	// Parameter: const char* fmt 可变参数格式字符串,如:%s%i%bi%b%d%dt%n
	// Parameter: ... 可变参数
	//************************************
	uint64_t executeInsert(const string& sql, const char* fmt, ...);

	//************************************
	// Method:    executeInsert
	// FullName:  SqlSession::executeInsert
	// Access:    public 
	// Returns:   uint64_t 自动增长ID值
	// Qualifier: 插入数据，用于数据库主键自增的数据表，主键非自增请使用executeUpdate
	// Parameter: const string & sql sql语句
	//************************************
	uint64_t executeInsert(const string& sql);

	//************************************
	// Method:    executeInsert
	// FullName:  SqlSession::executeInsert
	// Access:    public 
	// Returns:   uint64_t 自动增长ID值
	// Qualifier: 插入数据，用于数据库主键自增的数据表，主键非自增请使用executeUpdate
	// Parameter: const string & sql sql语句
	// Parameter: const SqlParams & params SQL语句填充参数
	//************************************
	uint64_t executeInsert(const string& sql, const SqlParams& params);
	
	//************************************
	// Method:    executeQueryNumerical
	// FullName:  SqlSession::executeQueryNumerical
	// Access:    public 
	// Returns:   uint64_t 整型数字
	// Qualifier: 查询一个整型数字，比如查询count、max这类数据
	// Parameter: const string & sql SQL语句
	// Parameter: const char* fmt 可变参数格式字符串,如:%s%i%bi%b%d%dt%n
	// Parameter: ... 可变参数
	//************************************
	uint64_t executeQueryNumerical(const string& sql, const char* fmt, ...);

	//************************************
	// Method:    executeQueryNumerical
	// FullName:  SqlSession::executeQueryNumerical
	// Access:    public 
	// Returns:   uint64_t 整型数字
	// Qualifier: 查询一个整型数字，比如查询count、max这类数据
	// Parameter: const string & sql SQL语句
	//************************************
	uint64_t executeQueryNumerical(const string& sql);

	//************************************
	// Method:    executeQueryNumerical
	// FullName:  SqlSession::executeQueryNumerical
	// Access:    public 
	// Returns:   uint64_t 整型数字
	// Qualifier: 查询一个整型数字，比如查询count、max这类数据
	// Parameter: const string & sql SQL语句
	// Parameter: const SqlParams & params SQL语句填充参数
	//************************************
	uint64_t executeQueryNumerical(const string& sql, const SqlParams& params);

	//************************************
	// Method:    executeQuery
	// FullName:  SqlSession::executeQuery
	// Access:    public 
	// Returns:   查询结果集合
	// Qualifier: 执行查询
	// Parameter: const string & sql SQL语句
	// Parameter: const M& mapper 查询结果匹配处理
	// Parameter: const char* fmt 可变参数格式字符串,如:%s%i%bi%b%d%dt%n
	// Parameter: ... 可变参数
	//************************************
	template<class T, typename M = Mapper<T>>
	std::list<T> executeQuery(const string& sql, const M& mapper, const char* fmt, ...) {
		std::list<T> list;
		try
		{
			NULL_PTR_CHECK(conn, "connection is null");
			//1 获取prepareStatement对象
			pstmt = conn->prepareStatement(sql);
			//2 处理参数
			SQL_ARG_EXEC_2(pstmt, fmt);
			//3 执行查询
			res = pstmt->executeQuery();
			//4 处理查询结果
			while (res->next()) {
				list.push_back(mapper.mapper(res));
			}
			//5 释放资源
			releaseResultSet();
			releasePreparedStatement();
		}
		catch (const std::exception& e)
		{
			//5 释放资源
			releaseResultSet();
			releasePreparedStatement();
			cerr << "ExecuteQuery Exception. " << e.what() << endl;
		}
		return list;
	}

	//************************************
	// Method:    executeQuery
	// FullName:  SqlSession::executeQuery
	// Access:    public 
	// Returns:   查询结果集合
	// Qualifier: 执行查询
	// Parameter: const string & sql SQL语句
	// Parameter: const M& mapper 查询结果匹配处理
	//************************************
	template<class T, typename M = Mapper<T>>
	std::list<T> executeQuery(const string& sql, const M& mapper) {
		std::list<T> list;
		TryFinally(
			[&] {
				NULL_PTR_CHECK(conn, "connection is null");
				//1 获取prepareStatement对象
				pstmt = conn->prepareStatement(sql);
				//2 执行查询
				res = pstmt->executeQuery();
				//3 处理查询结果
				while (res->next()) {
					list.push_back(mapper.mapper(res));
				}
			},
			[](const std::exception& e){
				cerr << "ExecuteQuery Exception. " << e.what() << endl;
			},
			[=] {
				//4 释放资源
				releaseResultSet();
				releasePreparedStatement();
			}
		);
		return list;
	}

	//************************************
	// Method:    executeQuery
	// FullName:  SqlSession::executeQuery
	// Access:    public 
	// Returns:   查询结果集合
	// Qualifier: 执行查询
	// Parameter: const string & sql SQL语句
	// Parameter: const M& mapper 查询结果匹配处理
	// Parameter: const SqlParams & params SQL语句填充参数
	//************************************
	template<class T, typename M = Mapper<T>>
	std::list<T> executeQuery(const string& sql, const M& mapper, const SqlParams& params) {
		std::list<T> list;
		try
		{
			NULL_PTR_CHECK(conn, "connection is null");
			//1 获取prepareStatement对象
			pstmt = conn->prepareStatement(sql);
			//2 处理参数
			SQL_ARG_EXEC_3(params, pstmt);
			//3 执行查询
			res = pstmt->executeQuery();
			//4 处理查询结果
			while (res->next()) {
				list.push_back(mapper.mapper(res));
			}
			//5 释放资源
			releaseResultSet();
			releasePreparedStatement();
		}
		catch (const std::exception& e)
		{
			//5 释放资源
			releaseResultSet();
			releasePreparedStatement();
			cerr << "ExecuteQuery Exception. " << e.what() << endl;
		}
		return list;
	}

	// 设置连接编码
	bool setCharset(const std::string& charset);

	// 启动事务
	void beginTransaction();

	// 提交事务
	void commitTransaction();

	// 事务回滚
	void rollbackTransaction();

	// 获取连接对象
	Connection* getConnection() { return this->conn; }
};
#endif // !_SQL_SESSION_
