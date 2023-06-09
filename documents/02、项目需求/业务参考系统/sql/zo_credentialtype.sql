/*
 Navicat Premium Data Transfer

 Source Server         : 01项目
 Source Server Type    : MySQL
 Source Server Version : 80020 (8.0.20)
 Source Host           : 8.130.89.148:3965
 Source Schema         : zohr_sys

 Target Server Type    : MySQL
 Target Server Version : 80020 (8.0.20)
 File Encoding         : 65001

 Date: 09/06/2023 17:53:22
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
INSERT INTO `zo_credentialtype` VALUES ('1', '执(职)业资格证书', '10', 1);
INSERT INTO `zo_credentialtype` VALUES ('2', '(岗位)技能证书', '5', 1);

SET FOREIGN_KEY_CHECKS = 1;
