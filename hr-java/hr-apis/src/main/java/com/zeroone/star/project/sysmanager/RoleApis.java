package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.constraints.NotBlank;

public interface RoleApis {
    /**
     * 通过编号查询角色角色详情信息
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<RoleDTO> queryById(@NotBlank(message = "id 不能为空")String id);

    /**
     * 删除角色
     * @param id
     * @return
     */
    JsonVO<Boolean>  deleteRole(@NotBlank(message = "id 不能为空")String id);

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
     * @param roleId 角色ID menuId 菜单ID
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean> assignMenus(@NotBlank(message = "id 不能为空")String roleId,@NotBlank(message = "id 不能为空")String menuId);

    /**
     * 角色删除菜单
     *
     * @param roleId 角色ID menuId 菜单ID
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean> deleteMenus(@NotBlank(message = "id 不能为空")String roleId,@NotBlank(message = "id 不能为空")String menuId);

    /**
     * 角色分配权限
     *
     * @param roleId 角色ID powerId 权限ID
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean> assignPermissions(@NotBlank(message = "id 不能为空")String roleId,@NotBlank(message = "id 不能为空")String powerId);

    /**
     * 角色删除权限
     *
     * @param roleId 角色ID powerId 权限ID
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean>  deletePermissions(@NotBlank(message = "id 不能为空")String roleId,@NotBlank(message = "id 不能为空")String powerId);

    /**
     * 修改状态
     * @param id ID
     * @return 修改结果
     */
    JsonVO<Boolean> modifyStatus(@NotBlank(message = "id 不能为空") String id);
}
