package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;
/**
 * <p>
 * 用户权限表 Mapper 接口
 * </p>
 *
 * @author sleephea
 * @since 2023-05-27
 */
@Mapper
public interface RolePowerMapper {
    int assignPower(@Param("roleId") String roleId, @Param("powerId") String powerId);

    int deletePower(@Param("roleId") String roleId, @Param("powerId") String powerId);

    List<String> getPowerIdsByRoleId(@Param("roleId") String roleId);

    int checkRolePower(@Param("roleId") String roleId, @Param("powerId") String powerId);
}
