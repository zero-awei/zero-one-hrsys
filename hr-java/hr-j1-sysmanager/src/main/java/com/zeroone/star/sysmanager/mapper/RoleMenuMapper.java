package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 * 用户菜单表 Mapper 接口
 * </p>
 *
 * @author sleephea
 * @since 2023-05-27
 */
@Mapper
public interface RoleMenuMapper {

    int assignMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);

    int deleteMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);

    List<String> getMenuIdsByRoleId(@Param("roleId") String roleId);

    int checkRoleMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);
}