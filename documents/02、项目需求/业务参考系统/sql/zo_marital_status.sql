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

 Date: 24/05/2023 19:18:55
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_marital_status
-- ----------------------------
DROP TABLE IF EXISTS `zo_marital_status`;
CREATE TABLE `zo_marital_status`  (
  `id` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '婚姻状况ID',
  `marital_status_type` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '婚姻状况类型',
  `marital_status_code` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '婚姻状态类型代码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_marital_status
-- ----------------------------
INSERT INTO `zo_marital_status` VALUES ('1', '未婚', '1');
INSERT INTO `zo_marital_status` VALUES ('2', '已婚', '2');
INSERT INTO `zo_marital_status` VALUES ('3', '离婚', '3');
INSERT INTO `zo_marital_status` VALUES ('4', '丧偶', '4');

SET FOREIGN_KEY_CHECKS = 1;
