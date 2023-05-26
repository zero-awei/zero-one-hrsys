package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.sysmanager.rolemenumanager.RoleMenuDTO;

public interface RoleMenuService {
    Boolean assignMenus(RoleMenuDTO dto);

    Boolean deleteMenus(RoleMenuDTO dto);

    String getMenuIdsByRoleId(String roleId);

}
