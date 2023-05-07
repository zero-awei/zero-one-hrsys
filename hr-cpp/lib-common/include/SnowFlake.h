#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/02 14:35:47

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
#ifndef _SNOWFLAKE_H_
#define _SNOWFLAKE_H_
#include <stdint.h>
#include <mutex>

/**
 * 雪花ID生成工具
 * 使用示例：
 * 下面示例生成10个ID
 * SnowFlake sf(1, 1);
 * for (int i = 0; i < 10; i++)
 *	std::cout << sf.nextId() << std::endl;
 */
class SnowFlake
{
private:
	// 初始时间戳，给一个随机值
	static const uint64_t m_start_time_stamp = 1480166465631;
	// 序列号占用位数
	static const uint64_t m_sequence_bit = 12;
	// 机器ID占用位数
	static const uint64_t m_machine_bit = 5;
	// 数据标识占用位数
	static const uint64_t m_datacenter_bit = 5;

	// 获取位数的最大值
	static const uint64_t m_max_datacenter_num = -1 ^ (uint64_t(-1) << m_datacenter_bit);
	static const uint64_t m_max_machine_num = -1 ^ (uint64_t(-1) << m_machine_bit);
	static const uint64_t m_max_sequence_num = -1 ^ (uint64_t(-1) << m_sequence_bit);

	// 下标
	static const uint64_t m_machine_left = m_sequence_bit;// 机器ID向左移12位
	static const uint64_t m_datacenter_left = m_sequence_bit + m_machine_bit;// 数据标识ID向左移17位(12+5)
	static const uint64_t m_timestamp_left = m_sequence_bit + m_machine_bit + m_datacenter_bit; // 时间戳向左移22位(5+5+12)

	// 数据中心ID(0~31)
	uint64_t m_datacenterId;
	// 工作机器ID(0~31)
	uint64_t m_machineId;
	// 毫秒内序列(0~4095)
	uint64_t m_sequence;
	// 上次生成ID的时间戳
	uint64_t m_last_time_stamp;
	// 标识是否初始化完成
	bool m_is_init;
	// 线程锁
	std::mutex m_mtx;
	// 获得新的时间戳
	uint64_t getNextMill();
	// 返回以毫秒为单位的当前时间
	uint64_t getNewTimeStamp();
public:
	//************************************
	// Method:    SnowFlake
	// FullName:  SnowFlake::SnowFlake
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: int datacenterId 数据中心ID (0~31)
	// Parameter: int machineId 工作机器ID(0~31)
	//************************************
	SnowFlake(int datacenterId, int machineId);

	//************************************
	// Method:    nextId
	// FullName:  SnowFlake::nextId
	// Access:    public 
	// Returns:   uint64_t 返回计算出来的ID，返回0表示生成ID失败
	// Qualifier: 获取下一个ID
	//************************************
	uint64_t nextId();
};


#endif // _SNOWFLAKE_H_
