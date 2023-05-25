package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.Dt;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  部门类型 Mapper 接口
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Mapper
public interface DtMapper extends BaseMapper<Dt> {
    @Select("select `sector_type_code` AS `key`, `sector_type` AS `value` from zo_sector_type;")
    List<DropdownListOptionDTO> listDt();
}
