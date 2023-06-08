package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.dto.sysmanager.rolemenumanager.RoleMenuDTO;
import com.zeroone.star.project.dto.sysmanager.rolepowermanager.RolePowerDTO;
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
     * @param dto 用户菜单对象
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean> assignMenus(RoleMenuDTO dto);

    /**
     * 角色删除菜单
     *
     * @param dto 用户菜单对象
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean> deleteMenus(RoleMenuDTO dto);

    /**
     * 角色分配权限
     *
     * @param dto 用户权限对象
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean> assignPermissions(RolePowerDTO dto);

    /**
     * 角色删除权限
     *
     * @param dto 用户权限对象
     * @return Boolean 是否成功状态
     */
    JsonVO<Boolean>  deletePermissions(RolePowerDTO dto);

    /**
     * 修改状态
     * @param id ID
     * @return 修改结果
     */
    JsonVO<Boolean> modifyStatus(@NotBlank(message = "id 不能为空") String id);
}
