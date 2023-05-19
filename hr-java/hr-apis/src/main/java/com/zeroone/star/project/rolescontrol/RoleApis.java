package com.zeroone.star.project.rolescontrol;

import com.zeroone.star.project.dto.rolescontrol.RoleMenuDTO;
import com.zeroone.star.project.dto.rolescontrol.RolePermissionDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface RoleApis {
    /**
     * 角色分配菜单
     *
     * @param roleId 角色ID
     * @return RoleMenuDTO 角色ID和菜单ID列表
     */
    JsonVO<RoleMenuDTO> assignMenus(int roleId);

    /**
     * 角色删除菜单
     *
     * @param roleId 角色ID
     * @return RoleMenuDTO 角色ID和菜单ID列表
     */
    JsonVO<RoleMenuDTO> deleteMenus(int roleId);

    /**
     * 角色分配权限
     *
     * @param roleId 角色ID
     * @return RolePermissionDTO 角色ID和权限ID列表
     */
    JsonVO<RolePermissionDTO> assignPermissions(int roleId);

    /**
     * 角色删除权限
     *
     * @param roleId 角色ID
     * @return RolePermissionDTO 角色ID和权限ID列表
     */
    JsonVO<RolePermissionDTO>  deletePermissions(int roleId);

}