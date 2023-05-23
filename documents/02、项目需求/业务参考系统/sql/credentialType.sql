-- table structure for zo_credentialtype
CREATE TABLE `zo_credentialtype` (
    `id` VARCHAR(60) NOT NULL COMMONT '证书类型ID', 
    `name` VARCHAR(60) NOT NULL COMMONT DEFAULT 'NULL' '证书类型名称',
    `code` varchar(60) NOT NULL COMMENT '证书类型代号',
    `validity` TINYINT(1) NOT NULL DEFAULT '1' COMMENT '是否有效 (0无效, 1有效)',
    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8mb4_0900_ai_ci COMMENT='证书类型';

-- initiate some records for zo_credentialtype
INSERT INTO `zo_credentialType` VALUES ('1', '执（职）业资格证书', '10', 1);
INSERT INTO `zo_credentialType` VALUES ('2', '（岗位）技能证书', '5', 1);
