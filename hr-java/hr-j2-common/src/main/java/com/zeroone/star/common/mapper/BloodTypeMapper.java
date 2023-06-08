package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.BloodType;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 血型 Mapper 接口
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-29
 */
@Mapper
public interface BloodTypeMapper extends BaseMapper<BloodType> {

    @Select("select `code` AS `key`, `name` AS `value` from zo_blood_type;")
    List<DropdownListOptionDTO> selectBloodType();
}
