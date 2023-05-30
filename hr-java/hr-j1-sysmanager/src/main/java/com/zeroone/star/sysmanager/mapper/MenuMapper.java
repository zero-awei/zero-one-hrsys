package com.zeroone.star.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanager.entity.Menu;
import org.apache.ibatis.annotations.Mapper;

/**
 * The mapper of {@link Menu}, base on {@link BaseMapper}
 *
 * @author camille
 * @see Menu
 * @see BaseMapper
 */
@Mapper
public interface MenuMapper extends BaseMapper<Menu> {
}
