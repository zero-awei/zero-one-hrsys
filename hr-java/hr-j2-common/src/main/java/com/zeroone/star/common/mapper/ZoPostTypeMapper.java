package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.ZoPostType;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 岗位分类 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
@Mapper
public interface ZoPostTypeMapper extends BaseMapper<ZoPostType> {

    @Select("select post_type_code as 'key', post_type as 'value' from zo_post_type;")
    List<DropdownListOptionDTO> selectPostType();
}
