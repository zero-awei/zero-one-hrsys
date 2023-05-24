/*
 Navicat Premium Data Transfer

 Source Server         : Docker容器中的MySQL
 Source Server Type    : MySQL
 Source Server Version : 80020
 Source Host           : 192.168.164.128:3306
 Source Schema         : test

 Target Server Type    : MySQL
 Target Server Version : 80020
 File Encoding         : 65001

 Date: 24/05/2023 19:18:48
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_credentialtype
-- ----------------------------
DROP TABLE IF EXISTS `zo_credentialtype`;
CREATE TABLE `zo_credentialtype`  (
  `id` varchar(60) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '证书类型ID',
  `name` varchar(60) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '证书类型名称',
  `code` varchar(60) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '证书类型代号',
  `validity` tinyint(1) NOT NULL DEFAULT 1 COMMENT '是否有效 (0无效, 1有效)',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '证书类型' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_credentialtype
-- ----------------------------
INSERT INTO `zo_credentialtype` VALUES ('1', '中级软件设计师', '3', 1);
INSERT INTO `zo_credentialtype` VALUES ('2', '会计从业资格证', '4', 1);
INSERT INTO `zo_credentialtype` VALUES ('3', '一级建造师建筑工程专业', '6', 1);
INSERT INTO `zo_credentialtype` VALUES ('4', '资产评估师', '7', 1);

SET FOREIGN_KEY_CHECKS = 1;
