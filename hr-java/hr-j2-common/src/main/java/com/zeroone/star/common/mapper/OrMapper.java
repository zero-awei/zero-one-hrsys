package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.Or;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  所属区域 Mapper 接口
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Mapper
public interface OrMapper extends BaseMapper<Or> {
    @Select("select `area_code` AS `key`, `area_type` AS `value` from zo_area;")
    List<DropdownListOptionDTO> listOr();
}
//CREATE TABLE `zo_area` (
//  `id` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '所属区域ID',
//  `area_type` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL COMMENT '所属区域类型',
//  `area_code` varchar(60) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL COMMENT '所属区域状态码',
//  PRIMARY KEY (`id`)
//) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='所属区域';