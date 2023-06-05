package com.zeroone.star.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanager.entity.Menu;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * The mapper of {@link Menu}, base on {@link BaseMapper}
 *
 * @author camille
 * @see Menu
 * @see BaseMapper
 */
@Mapper
public interface MenuMapper extends BaseMapper<Menu> {
    /**
     * 通过角色名获取对应的菜单资源
     * @param roleName 角色名
     * @return 返回菜单列表
     */
    List<Menu> selectByRoleName(String roleName);
}
