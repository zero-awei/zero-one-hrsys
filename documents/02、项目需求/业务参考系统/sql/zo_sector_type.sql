/*
 Navicat Premium Data Transfer

 Source Server         : 8.130.89.148
 Source Server Type    : MySQL
 Source Server Version : 80020
 Source Host           : 8.130.89.148:3965
 Source Schema         : zohr_sys

 Target Server Type    : MySQL
 Target Server Version : 80020
 File Encoding         : 65001

 Date: 25/05/2023 19:57:31
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_sector_type
-- ----------------------------
DROP TABLE IF EXISTS `zo_sector_type`;
CREATE TABLE `zo_sector_type`  (
  `id` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '部门类型ID',
  `sector_type` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '部门类型',
  `sector_type_code` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '部门类型状态码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = '部门类型' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_sector_type
-- ----------------------------
INSERT INTO `zo_sector_type` VALUES ('1', '机关部门', '1');
INSERT INTO `zo_sector_type` VALUES ('2', '项目部门', '2');

SET FOREIGN_KEY_CHECKS = 1;
