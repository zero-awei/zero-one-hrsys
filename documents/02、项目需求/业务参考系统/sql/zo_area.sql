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

 Date: 25/05/2023 19:55:53
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_area
-- ----------------------------
DROP TABLE IF EXISTS `zo_area`;
CREATE TABLE `zo_area`  (
  `id` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '所属区域ID',
  `area_type` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '所属区域类型',
  `area_code` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '所属区域状态码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = '所属区域' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_area
-- ----------------------------
INSERT INTO `zo_area` VALUES ('1', '华东地区', '1');
INSERT INTO `zo_area` VALUES ('10', '其他', '10');
INSERT INTO `zo_area` VALUES ('2', '华南地区', '2');
INSERT INTO `zo_area` VALUES ('3', '华中地区', '3');
INSERT INTO `zo_area` VALUES ('4', '华北地区', '4');
INSERT INTO `zo_area` VALUES ('5', '西南地区', '5');
INSERT INTO `zo_area` VALUES ('6', '东北地区', '6');
INSERT INTO `zo_area` VALUES ('7', '西北地区', '7');
INSERT INTO `zo_area` VALUES ('8', '港澳台地区', '8');
INSERT INTO `zo_area` VALUES ('9', '海外', '9');

SET FOREIGN_KEY_CHECKS = 1;
