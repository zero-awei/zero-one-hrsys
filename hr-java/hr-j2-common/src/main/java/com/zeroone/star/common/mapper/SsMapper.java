package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.Ss;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  补贴类型 Mapper 接口
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Mapper
public interface SsMapper extends BaseMapper<Ss> {
    @Select("select `subsidy_standard_code` AS `key`, `subsidy_standard_type` AS `value` from zo_subsidy_standard;")
    List<DropdownListOptionDTO> listSs();
}
