#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:32:41
 
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
#ifndef _COMMONMACROS_H_
#define _COMMONMACROS_H_

#ifdef LINUX
#include <unistd.h>
#include <sys/stat.h>
#else
#include <io.h>
#include <direct.h> 
#endif

#define MAX_DIR_LEN 512

#ifdef LINUX
// 检查文件夹访问性
#define ACCESS(fileName, accessMode) access(fileName, accessMode)
// 创建文件夹
#define MKDIR(path) mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#else
// 检查文件夹访问性
#define ACCESS(fileName, accessMode) _access(fileName, accessMode)
// 创建文件夹
#define MKDIR(path) _mkdir(path)
#endif

#endif // _COMMONMACROS_H_
