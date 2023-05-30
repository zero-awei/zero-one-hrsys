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

 Date: 30/05/2023 17:27:32
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_post_type
-- ----------------------------
DROP TABLE IF EXISTS `zo_post_type`;
CREATE TABLE `zo_post_type`  (
  `id` varchar(64) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL COMMENT '岗位分类ID',
  `post_type` varchar(60) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL COMMENT '岗位分类',
  `post_type_code` varchar(60) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL COMMENT '岗位分类状态码',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci COMMENT = '岗位分类' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of zo_post_type
-- ----------------------------
INSERT INTO `zo_post_type` VALUES ('1', '党内', '1');
INSERT INTO `zo_post_type` VALUES ('2', '行政', '2');

SET FOREIGN_KEY_CHECKS = 1;
