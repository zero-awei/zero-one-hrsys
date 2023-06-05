package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface UserRoleMapper {
    int assignRole(@Param("roleId") String roleId, @Param("menuId") String menuId);
}
