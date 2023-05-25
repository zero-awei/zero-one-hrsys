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

 Date: 25/05/2023 19:57:20
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_tissue_nature
-- ----------------------------
DROP TABLE IF EXISTS `zo_tissue_nature`;
CREATE TABLE `zo_tissue_nature`  (
  `id` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '组织性质ID',
  `tissue_nature_type` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '组织性质类别',
  `tissue_nature_code` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '组织性质状态码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = '组织性质' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_tissue_nature
-- ----------------------------
INSERT INTO `zo_tissue_nature` VALUES ('1', '法人单位', '1');
INSERT INTO `zo_tissue_nature` VALUES ('2', '非法人单位', '2');

SET FOREIGN_KEY_CHECKS = 1;
