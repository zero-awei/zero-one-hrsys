package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.project.sysmanager.RolesApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.service.IRoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.management.relation.Role;

/**
 * <p>
 * 角色表 前端控制器
 * </p>
 *
 * @author alan
 * @since 2023-05-20
 */

@Slf4j
@RestController
@Api(tags="角色管理")
@RequestMapping("/roles")
public class RoleController implements RoleApis {

    @GetMapping("query-one")
    @ApiOperation(value = "查询一个角色")
    @Override
    public JsonVO<RoleDTO> queryById(Integer id) {
        return null;
    }
    @ApiOperation(value = "删除角色")
    @DeleteMapping("delete")
    @Override
    public JsonVO<Boolean> deleteByName(RoleDTO dto) {
        return null;
    }
    @ApiOperation(value = "增加角色")
    @PostMapping("add-one")
    @Override
    public JsonVO<Boolean> addOneRole(RoleDTO dto) {
        return null;
    }
    @ApiOperation(value = "修改角色")
    @PutMapping("modify")
    @Override
    public JsonVO<Boolean> modifyRole(RoleDTO dto) {
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

