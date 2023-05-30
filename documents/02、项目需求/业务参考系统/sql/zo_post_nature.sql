/*
 Navicat Premium Data Transfer

 Source Server         : wang
 Source Server Type    : MySQL
 Source Server Version : 80030
 Source Host           : localhost:3306
 Source Schema         : ibizehr

 Target Server Type    : MySQL
 Target Server Version : 80030
 File Encoding         : 65001

 Date: 30/05/2023 17:30:29
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_post_nature
-- ----------------------------
DROP TABLE IF EXISTS `zo_post_nature`;
CREATE TABLE `zo_post_nature`  (
  `id` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL COMMENT '岗位性质ID',
  `post_nature` varchar(60) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL COMMENT '岗位性质',
  `post_nature_code` varchar(60) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL COMMENT '岗位性质状态码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci COMMENT = '岗位性质' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_post_nature
-- ----------------------------
INSERT INTO `zo_post_nature` VALUES ('1', '标准工时制', '1');
INSERT INTO `zo_post_nature` VALUES ('2', '非标准工时制', '2');

SET FOREIGN_KEY_CHECKS = 1;
