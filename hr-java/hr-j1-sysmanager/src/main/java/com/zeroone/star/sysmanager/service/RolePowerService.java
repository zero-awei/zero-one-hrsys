package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.sysmanager.rolepowermanager.RolePowerDTO;

import java.util.List;

public interface RolePowerService {
    Boolean assignPermissions(RolePowerDTO dto);

    Boolean deletePermissions(RolePowerDTO dto);

    List<String> getPowerIdsByRoleId(String roleId);

    Boolean checkRoleMenu(RolePowerDTO dto);
}
