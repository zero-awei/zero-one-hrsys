/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:19:12
 
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
#include "stdafx.h"
#include "TestDb.h"
#include "SqlSession.h"
#include "LibTest.h"
#include "TransactionManager.h"

void TestDb::testSS()
{
	SqlSession sqlsession;
	//设置一下编码
	sqlsession.setCharset("GBK");
	//创建表
	string table = "CREATE TABLE IF NOT EXISTS `lib_test` (`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,`first` text NOT NULL,`last` text NOT NULL,`age` smallint(5) unsigned NOT NULL,PRIMARY KEY(`id`)) ENGINE = InnoDB DEFAULT CHARSET = utf8";
	sqlsession.execute(table);
	//插入数据
	string fullSql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES('姓', '名', '96')";
	string sql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES(?, ?, ?)";
	uint64_t id = sqlsession.executeInsert(fullSql);
	cout << "id is " << id << endl;
	id = sqlsession.executeInsert(sql, "cs%cs%i", "小", "妖精", 97);
	cout << "id is " << id << endl;
	//查询数据
	string qsql = "SELECT * FROM `lib_test` WHERE id=?";
	string qfullSql = "SELECT * FROM `lib_test`";
	LibTestMapper mapper;
	list<LibTest> results = sqlsession.executeQuery<LibTest, LibTestMapper>(qsql, mapper, "cs", "2");
	cout << "query id is 2:" << endl;
	if (results.size() != 0) {
		LibTest sub = results.front();
		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
	}
	cout << "query all:" << endl;
	results = sqlsession.executeQuery<LibTest, LibTestMapper>(qfullSql, mapper);
	for (LibTest sub : results)
	{
		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
	}

	//测试事务
	cout << "test transaction begin" << endl;
	sqlsession.beginTransaction();
	string usql = "UPDATE `lib_test` SET `first`='大' WHERE `id`=2";
	int row = sqlsession.executeUpdate(usql);
	id = sqlsession.executeInsert(sql, "s%s%i", string("小"), string("火子"), 98);
	if (row == 1) sqlsession.commitTransaction();
	else sqlsession.rollbackTransaction();
	cout << "test transaction end" << endl;

	//事务结束再提交一条数据,测试是否可以正常提交数据
	id = sqlsession.executeInsert(sql, "cs%cs%i", "小", "妖精", 99);
	cout << "id is " << id << endl;
}

void TestDb::testTM()
{
	//定义事务管理器
	LibTestDAO1 d1;
	LibTestDAO2 d2;
	d1.getSqlSession()->setCharset("GBK");
	d2.getSqlSession()->setCharset("GBK");
	TransactionManager tm(&d1, &d2);

	//执行第一个DAO操作
	LibTest uObj;
	uObj.first = "李";
	uObj.id = 1;
	int row = d1.update(uObj);
	//执行第二个DAO操作
	row = row + d2.deleteById(6);
	//判断是否提交事务
	if (row == 2)
	{
		cout << "tm commit" << endl;
		tm.commit();
	}
	else
	{
		cout << "tm rollback" << endl;
		tm.rollback();
	}
}
