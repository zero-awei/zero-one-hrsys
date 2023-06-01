package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.Op;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  组织性质 Mapper 接口
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Mapper
public interface OpMapper extends BaseMapper<Op> {
    @Select("select `tissue_nature_code` AS `key`, `tissue_nature_type` AS `value` from zo_tissue_nature;")
    List<DropdownListOptionDTO> listOp();
}
