package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.StaffingControl;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 编制控制 Mapper 接口
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-25
 */
@Mapper
public interface StaffingControlMapper extends BaseMapper<StaffingControl> {

    @Select("select `code` AS `key`, `name` AS `value` from zo_staffing_control;")
    List<DropdownListOptionDTO> listStaffingControl();
}
