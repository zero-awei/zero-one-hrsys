/*
 Navicat Premium Data Transfer

 Source Server         : zohr
 Source Server Type    : MySQL
 Source Server Version : 80020
 Source Host           : 8.130.89.148:3965
 Source Schema         : zohr_sys

 Target Server Type    : MySQL
 Target Server Version : 80020
 File Encoding         : 65001

 Date: 23/05/2023 10:07:16
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_document_type
-- ----------------------------
DROP TABLE IF EXISTS `zo_document_type`;
CREATE TABLE `zo_document_type`  (
  `id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '证件类型ID',
  `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '证件类型名称',
  `code` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '证件类型代号',
  `is_valid` tinyint(1) NOT NULL DEFAULT 1 COMMENT '是否有效（0表示无效，1表示有效）',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '证件类型' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_document_type
-- ----------------------------
INSERT INTO `zo_document_type` VALUES ('1', '身份证', '10', 1);
INSERT INTO `zo_document_type` VALUES ('2', '护照', '20', 1);
INSERT INTO `zo_document_type` VALUES ('3', '其他', '30', 1);

SET FOREIGN_KEY_CHECKS = 1;
