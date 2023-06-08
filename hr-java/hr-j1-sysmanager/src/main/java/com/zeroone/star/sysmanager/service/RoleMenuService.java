package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.sysmanager.rolemenumanager.RoleMenuDTO;

import java.util.List;

public interface RoleMenuService {
    Boolean assignMenus(RoleMenuDTO dto);

    Boolean deleteMenus(RoleMenuDTO dto);

    List<String> getMenuIdsByRoleId(String roleId);

    Boolean checkRoleMenu(RoleMenuDTO dto);

}
