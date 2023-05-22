package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleMenuDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RolePermissionDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

import javax.management.relation.Role;

public interface RoleApis {
    /**
     * 通过编号查询角色
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<RoleDTO> queryById(Integer id);

    /**
     * 通过角色名字删除
     * @param name
     * @return
     */
    JsonVO<Void>  deleteByName(String name);

    /**
     * 新增一个角色
     * @param id
     * @param name
     * @param keyword
     * @param description
     * @return
     */
    JsonVO<RoleDTO> insertOneRole(Integer id, String name,String keyword,String description);

    /**
     * 修改一个角色
     * @param role
     * @return
     */
    JsonVO<RoleDTO> modifyOneRole(Role role);

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
