package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface RoleMenuMapper {

    int assignMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);

    int deleteMenu(@Param("roleId") String roleId, @Param("menuId") String menuId);

    List<String> getMenuIdsByRoleId(@Param("roleId") String roleId);
}