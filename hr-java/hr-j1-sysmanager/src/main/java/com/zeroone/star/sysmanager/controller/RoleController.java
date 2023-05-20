package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleMenuDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RolePermissionDTO;
import com.zeroone.star.project.sysmanager.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import javax.management.relation.Role;

/**
 * <p>
 * 角色表 前端控制器
 * </p>
 *
 * @author alan
 * @since 2023-05-20
 */
@RestController
@Api(tags="角色管理")
@RequestMapping("/roles")
public class RoleController implements RoleApis {

    @GetMapping("query-by-id")
    @ApiOperation(value = "编号查询")
    @Override
    public JsonVO<RoleDTO> queryById(Integer id) {
        return null;
    }

    @GetMapping("query-by-name")
    @ApiOperation(value = "名称查询")
    @Override
    public JsonVO<Void> deleteByName(String name) {
        return null;
    }

    @GetMapping("add")
    @ApiOperation(value = "添加角色")
    @Override
    public JsonVO<RoleDTO> insertOneRole(Integer id, String name, String keyword, String description) {
        return null;
    }

    @GetMapping("modify")
    @ApiOperation(value = "修改角色")
    @Override
    public JsonVO<RoleDTO> modifyOneRole(Role role) {
        return null;
    }

    @GetMapping("assign-menus")
    @ApiOperation(value = "角色分配菜单")
    @Override
    public JsonVO<RoleMenuDTO> assignMenus(int roleId) {
        return null;
    }

    @GetMapping("delete-menus")
    @ApiOperation(value = "角色删除菜单")
    @Override
    public JsonVO<RoleMenuDTO> deleteMenus(int roleId) {
        return null;
    }

    @GetMapping("assign-permissions")
    @ApiOperation(value = "角色分配权限")
    @Override
    public JsonVO<RolePermissionDTO> assignPermissions(int roleId) {
        return null;
    }

    @GetMapping("delete-permissions")
    @ApiOperation(value = "角色删除权限")
    @Override
    public JsonVO<RolePermissionDTO> deletePermissions(int roleId) {
        return null;
    }
}

