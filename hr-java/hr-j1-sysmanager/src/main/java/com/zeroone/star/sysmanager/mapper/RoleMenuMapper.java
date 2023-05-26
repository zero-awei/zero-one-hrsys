package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface RoleMenuMapper {

    int assignMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);

    int deleteMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);

    String getMenuIdsByRoleId(@Param("roleId") String roleId);
}