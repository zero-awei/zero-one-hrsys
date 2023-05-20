#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:06:42

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
#ifndef _MACROS_
#define _MACROS_
#include "YamlHelper.h"

/** �����ܱ����ı��������ṩget��set���� */
#define CC_SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: varType get##funName(void) const { return varName; }\
public: void set##funName(varType var){	varName = var; }

/** �����ܱ�����map���������ṩget��set���� */
#define CC_SYNTHESIZE_MAP(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: std::map<keyType, valType> get##funName(void) const { return varName; }\
public: void set##funName(std::map<keyType,valType> var){ varName = var; }

/** �����ܱ����ı��������ṩget���� */
#define CC_SYNTHESIZE_GET(varType, varName, funName)\
protected: varType varName;\
public: varType get##funName(void) const { return varName; }

/** �����ܱ�����map���������ṩget���� */
#define CC_SYNTHESIZE_MAP_GET(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: std::map<keyType, valType> get##funName(void) const { return varName; }\

/** �����ܱ����ı��������ṩset���� */
#define CC_SYNTHESIZE_SET(varType, varName, funName)\
protected: varType varName;\
public: void set##funName(varType var){	varName = var; }

/** �����ܱ�����map���������ṩset���� */
#define CC_SYNTHESIZE_MAP_SET(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: void set##funName(std::map<keyType,valType> var){ varName = var; }

/** �����ܱ����ı��������ṩget���������ر������� */
#define CC_SYNTHESIZE_CR_GET(varType, varName, funName)\
protected: varType varName;\
public: varType& get##funName(void) { return varName; }\

/** �����ܱ�����map���������ṩget����������map���� */
#define CC_SYNTHESIZE_CR_MAP_GET(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: std::map<keyType, valType>& get##funName(void) { return varName; }\

/** �����ܱ����ı��������ṩ��get��set���� */
#define CC_SYNTHESIZE_VIRTUAL(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

/** �����ܱ����ı��������ṩ��get���� */
#define CC_SYNTHESIZE_VIRTUAL_GET(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }

/** �����ܱ����ı��������ṩ��set���� */
#define CC_SYNTHESIZE_VIRTUAL_SET(varType, varName, funName)\
protected: varType varName;\
public: virtual void set##funName(varType var){ varName = var; }

/** �����ܱ����ı��������ṩ��get���������ر������� */
#define CC_SYNTHESIZE_VIRTUAL_CR_GET(varType, varName, funName)\
protected: varType varName;\
public: virtual varType& get##funName(void) { return varName; }

/** ˽�л���ֵ�����/��������/�޲ι��� */
#define SINGLETON_HEPLER(TypeName) \
private: \
TypeName() { init(); } \
TypeName(const TypeName&) = delete; \
TypeName& operator=(const TypeName&) = delete;

/** ���嵥����ע�⣺��Ҫ���Լ��������ṩһ��˽��init�������ڳ�ʼ������ */
#define DECLARE_INSTANCE(TypeName) \
SINGLETON_HEPLER(TypeName) \
public: \
	static TypeName& getInstance() { \
		static TypeName instance; \
		return instance; \
	} 

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

// RocketMQ�첽����������Ϣ������Ὣ����ת����JSON�ַ���
#define RC_PUBLISH_OBJ_MSG_ASYNC(__ROCKET_CLIENT__, __TOPIC__, __DATA_OBJ__, __CB_OBJ__) \
[&] { \
	auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared(); \
	auto jobj = mapper->writeToString(__DATA_OBJ__); \
	__ROCKET_CLIENT__->productMsgAsync(__TOPIC__, jobj.getValue(""), __CB_OBJ__); \
}()

// RocketMQͬ������������Ϣ������Ὣ����ת����JSON�ַ���
#define RC_PUBLISH_OBJ_MSG_SYNC(__RETURN_VAR_NAME__, __ROCKET_CLIENT__, __TOPIC__, __DATA_OBJ__) \
rocketmq::SendStatus __RETURN_VAR_NAME__; \
[&] { \
	auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared(); \
	auto jobj = mapper->writeToString(__DATA_OBJ__); \
	__RETURN_VAR_NAME__ = __ROCKET_CLIENT__->productMsgSync(__TOPIC__, jobj.getValue("")); \
}()

// RocketMQ������Ϣ����JSON�ַ���ת���ɶ���
#define RC_RECEIVER_MSG_CONVERT(__RETURN_VAR_NAME__, __DATA__TYPE__, __PAYLOAD__) \
oatpp::Object<__DATA__TYPE__> __RETURN_VAR_NAME__; \
[&] { \
	auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared(); \
	__RETURN_VAR_NAME__ = mapper->readFromString<oatpp::Object<__DATA__TYPE__>>(__PAYLOAD__); \
}()

// ����һ����ȡ�����ֻ�ȡ��
#define ZH_WORDS_GETTER(_KEY_) \
YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), _KEY_)

#define ZO_STAR_EXPAND( x ) x
#define ZO_STAR_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, NAME, ...) NAME
#define ZO_STAR_PASTE(...) ZO_STAR_EXPAND(ZO_STAR_GET_MACRO(__VA_ARGS__, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE30, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE29, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE28, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE27, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE26, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE25, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE24, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE23, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE22, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE21, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE20, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE19, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE18, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE17, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE16, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE15, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE14, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE13, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE12, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE11, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE10, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE9, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE8, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE7, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE6, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE5, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE4, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE3, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE2, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE1, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE0, \
        ZO_STAR_PASTE0)(__VA_ARGS__))
#define ZO_STAR_PASTE0
#define ZO_STAR_PASTE1(target, src, func, v1, v2) func(target, src, v1, v2)
#define ZO_STAR_PASTE2(target, src, func, v1, v2, v3, v4) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE1(target, src, func, v3, v4)
#define ZO_STAR_PASTE3(target, src, func, v1, v2, v3, v4, v5, v6) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE2(target, src, func, v3, v4, v5, v6)
#define ZO_STAR_PASTE4(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE3(target, src, func, v3, v4, v5, v6, v7, v8)
#define ZO_STAR_PASTE5(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE4(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10)
#define ZO_STAR_PASTE6(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE5(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define ZO_STAR_PASTE7(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE6(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define ZO_STAR_PASTE8(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE7(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#define ZO_STAR_PASTE9(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE8(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#define ZO_STAR_PASTE10(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE9(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20)
#define ZO_STAR_PASTE11(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE10(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22)
#define ZO_STAR_PASTE12(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE11(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24)
#define ZO_STAR_PASTE13(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE12(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26)
#define ZO_STAR_PASTE14(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE13(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)
#define ZO_STAR_PASTE15(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE14(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)
#define ZO_STAR_PASTE16(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE15(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#define ZO_STAR_PASTE17(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE16(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define ZO_STAR_PASTE18(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE17(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36)
#define ZO_STAR_PASTE19(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE18(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38)
#define ZO_STAR_PASTE20(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE19(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40)
#define ZO_STAR_PASTE21(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE20(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42)
#define ZO_STAR_PASTE22(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE21(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)
#define ZO_STAR_PASTE23(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE22(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define ZO_STAR_PASTE24(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE23(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define ZO_STAR_PASTE25(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE24(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)
#define ZO_STAR_PASTE26(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE25(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52)
#define ZO_STAR_PASTE27(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE26(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54)
#define ZO_STAR_PASTE28(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE27(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)
#define ZO_STAR_PASTE29(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE28(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)
#define ZO_STAR_PASTE30(target, src, func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60) ZO_STAR_PASTE1(target, src, func, v1, v2) ZO_STAR_PASTE29(target, src, func, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)

// DOת��DTO��������
#define ZO_STAR_DOMAIN_FILED_DO_TO_DTO(target, src, f1, f2) target->f1=src.get##f2();
/**
* DOתDTO������
* @param target: ����ֵ����Ŀ�����
* @param src: ����ֵ��Դ����
* @param ...: �ֶβ�����Ŀ������ֶ���,��Դ����get�������ơ���:id,Id,name,Name......
*/
#define ZO_STAR_DOMAIN_DO_TO_DTO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, ZO_STAR_DOMAIN_FILED_DO_TO_DTO, __VA_ARGS__))

// DTOת��DO��������
#define ZO_STAR_DOMAIN_FILED_DTO_TO_DO(target, src, f1, f2) target.set##f1(src->f2.getValue({}));
/**
* DTOתDO������
* @param target: ����ֵ����Ŀ�����
* @param src: ����ֵ��Դ����
* @param ...: �ֶβ�����Ŀ�����set��������,��Դ�����ֶ�������:Id,id,Name,name......
*/
#define ZO_STAR_DOMAIN_DTO_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, ZO_STAR_DOMAIN_FILED_DTO_TO_DO, __VA_ARGS__))

#endif // !_MACROS_