/*
 Navicat Premium Data Transfer

 Source Server         : localhost
 Source Server Type    : MySQL
 Source Server Version : 80032 (8.0.32)
 Source Host           : localhost:3306
 Source Schema         : test1

 Target Server Type    : MySQL
 Target Server Version : 80032 (8.0.32)
 File Encoding         : 65001

 Date: 20/05/2023 12:44:23
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for zo_menu
-- ----------------------------
DROP TABLE IF EXISTS `zo_menu`;
CREATE TABLE `zo_menu`  (
  `id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '菜单id',
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '菜单名称',
  `path` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '菜单路由地址',
  `priority` int NULL DEFAULT NULL COMMENT '菜单显示优先级别',
  `icon` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '菜单图标',
  `description` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '菜单描述',
  `parent_meun_id` int NULL DEFAULT NULL COMMENT '父级菜单id',
  `level` int NULL DEFAULT NULL COMMENT '菜单层次',
  `is_enable` int NULL DEFAULT NULL COMMENT '是否启用',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '菜单表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_menu
-- ----------------------------
INSERT INTO `zo_menu` VALUES ('1', '系统管理', '/sysmange', NULL, NULL, '系统管理', NULL, 1, 1);

-- ----------------------------
-- Table structure for zo_power
-- ----------------------------
DROP TABLE IF EXISTS `zo_power`;
CREATE TABLE `zo_power`  (
  `id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '权限id',
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '权限名称',
  `link_url` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '链接地址',
  `priority` int NULL DEFAULT NULL COMMENT '显示级别',
  `parent_power_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '父级权限id',
  `level` int NULL DEFAULT NULL COMMENT '层次',
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '描述',
  `is_enable` int NULL DEFAULT NULL COMMENT '是否启用',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '权限表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_power
-- ----------------------------
INSERT INTO `zo_power` VALUES ('1', '查询权限', '/query-power', 1, 'sysmange', NULL, '分页查询权限', 1);

-- ----------------------------
-- Table structure for zo_role
-- ----------------------------
DROP TABLE IF EXISTS `zo_role`;
CREATE TABLE `zo_role`  (
  `id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '唯一ID',
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '角色名',
  `keyword` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '关键词',
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '角色描述',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '角色表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_role
-- ----------------------------
INSERT INTO `zo_role` VALUES ('1', '超级管理员', 'SUPER_ADMIN', '超级管理员');

-- ----------------------------
-- Table structure for zo_role_menu
-- ----------------------------
DROP TABLE IF EXISTS `zo_role_menu`;
CREATE TABLE `zo_role_menu`  (
  `role_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '角色id',
  `menu_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '菜单id',
  PRIMARY KEY (`role_id`) USING BTREE,
  INDEX `role_menu_role`(`menu_id` ASC) USING BTREE,
  CONSTRAINT `role_menu_menu` FOREIGN KEY (`role_id`) REFERENCES `zo_role` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `role_menu_role` FOREIGN KEY (`menu_id`) REFERENCES `zo_menu` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '角色菜单关系表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_role_menu
-- ----------------------------

-- ----------------------------
-- Table structure for zo_role_power
-- ----------------------------
DROP TABLE IF EXISTS `zo_role_power`;
CREATE TABLE `zo_role_power`  (
  `role_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `power_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`role_id`) USING BTREE,
  INDEX `role_power_power`(`power_id` ASC) USING BTREE,
  CONSTRAINT `role_power_power` FOREIGN KEY (`power_id`) REFERENCES `zo_power` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `role_power_role` FOREIGN KEY (`role_id`) REFERENCES `zo_role` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '角色权限关系表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_role_power
-- ----------------------------

-- ----------------------------
-- Table structure for zo_user
-- ----------------------------
DROP TABLE IF EXISTS `zo_user`;
CREATE TABLE `zo_user`  (
  `id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '用户id',
  `username` varchar(16) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '用户名称',
  `password` varchar(16) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '用户密码',
  `mail` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '邮箱',
  `phone` varchar(16) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '联系电话',
  `regist_time` datetime NULL DEFAULT NULL COMMENT '注册时间',
  `is_enable` int NULL DEFAULT NULL COMMENT '是否启用',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '用户表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_user
-- ----------------------------
INSERT INTO `zo_user` VALUES ('1', '张三', '123456', '4515@gmail.com', '1112223333', '2023-05-18 21:19:48', 1);

-- ----------------------------
-- Table structure for zo_user_role
-- ----------------------------
DROP TABLE IF EXISTS `zo_user_role`;
CREATE TABLE `zo_user_role`  (
  `user_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '用户id',
  `role_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '角色id',
  PRIMARY KEY (`user_id`) USING BTREE,
  INDEX `user_role_role`(`role_id` ASC) USING BTREE,
  CONSTRAINT `user_role_role` FOREIGN KEY (`role_id`) REFERENCES `zo_role` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `user_role_user` FOREIGN KEY (`user_id`) REFERENCES `zo_user` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = '用户角色关系表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of zo_user_role
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;
