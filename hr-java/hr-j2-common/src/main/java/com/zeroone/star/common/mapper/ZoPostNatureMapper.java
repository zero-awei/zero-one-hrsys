package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.ZoPostNature;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 岗位性质 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
@Mapper
public interface ZoPostNatureMapper extends BaseMapper<ZoPostNature> {

    @Select("select post_nature_code as 'key', post_nature as 'value' from zo_post_nature;")
    List<DropdownListOptionDTO> selectPostNature();
}
