package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleMenuDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RolePermissionDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface RoleApis {
    /**
     * 通过编号查询角色
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<RoleDTO> queryById(Integer id);

    /**
     * 删除角色
     * @param dto
     * @return
     */
    JsonVO<Boolean>  deleteByName(RoleDTO dto);

    /**
     * 新增一个角色
     * @param dto 数据对象
     * @return
     */
    JsonVO<Boolean> addOneRole(RoleDTO dto);

    /**
     * 修改角色
     * @param dto 数据对象
     * @return
     */
    JsonVO<Boolean> modifyRole(RoleDTO dto);

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
