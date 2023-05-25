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

 Date: 25/05/2023 19:57:11
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_subsidy_standard
-- ----------------------------
DROP TABLE IF EXISTS `zo_subsidy_standard`;
CREATE TABLE `zo_subsidy_standard`  (
  `id` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '补贴标准ID',
  `subsidy_standard_type` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '补贴标准类型',
  `subsidy_standard_code` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '补贴标准状态码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = '补贴标准' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_subsidy_standard
-- ----------------------------
INSERT INTO `zo_subsidy_standard` VALUES ('1', 'A类地区', '1');
INSERT INTO `zo_subsidy_standard` VALUES ('2', 'B类地区', '2');
INSERT INTO `zo_subsidy_standard` VALUES ('3', 'C类地区', '3');
INSERT INTO `zo_subsidy_standard` VALUES ('4', 'D类地区', '4');

SET FOREIGN_KEY_CHECKS = 1;
