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

 Date: 24/05/2023 19:19:07
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_work_status
-- ----------------------------
DROP TABLE IF EXISTS `zo_work_status`;
CREATE TABLE `zo_work_status`  (
  `id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '工作状态ID',
  `work_status_type` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '工作状态类型',
  `work_status_code` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '工作状态类型代码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_work_status
-- ----------------------------
INSERT INTO `zo_work_status` VALUES ('1', '在职', '1');
INSERT INTO `zo_work_status` VALUES ('2', '离职', '2');
INSERT INTO `zo_work_status` VALUES ('3', '休假', '3');
INSERT INTO `zo_work_status` VALUES ('4', '停职', '4');
INSERT INTO `zo_work_status` VALUES ('5', '退休', '5');
INSERT INTO `zo_work_status` VALUES ('6', '返聘', '6');

SET FOREIGN_KEY_CHECKS = 1;
