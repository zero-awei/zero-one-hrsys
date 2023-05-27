package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface RolePowerMapper {
    int assignPower(@Param("roleId") String roleId, @Param("powerId") String powerId);

    int deletePower(@Param("roleId") String roleId, @Param("powerId") String powerId);

    List<String> getPowerIdsByRoleId(@Param("roleId") String roleId);
}
