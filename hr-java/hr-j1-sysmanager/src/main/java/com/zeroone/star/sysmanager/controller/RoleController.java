package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.sysmanager.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.IRoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

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
    @Resource
    IRoleService iRoleService;


    @GetMapping("/query-one")
    @ApiOperation(value = "查看角色详情")
    @Override
    public JsonVO<RoleDTO> queryById(String id) {
        Integer roleId = Integer.valueOf(id);
        return JsonVO.success(iRoleService.querRoleById(roleId));
    }
    @ApiOperation(value = "删除角色")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<Boolean> deleteRole(String id) {
        Integer roleId = Integer.valueOf(id);
        boolean result = iRoleService.deleRoleById(roleId);

        return null;
    }
    @ApiOperation(value = "增加角色")
    @PostMapping("/add-one")
    @Override
    public JsonVO<Boolean> addOneRole(RoleDTO dto) {
        if (dto.getId()==null&&
            dto.getDescription()==null&&
            dto.getName()==null&&
            dto.getKeyword()==null){
            return  null;

        }
        Boolean addResult = iRoleService.addRole(dto);
        return null;
    }
    @ApiOperation(value = "修改角色")
    @PutMapping("/modify")
    @Override
    public JsonVO<Boolean> modifyRole(RoleDTO dto) {
        //输入的id不能为空
        if (dto.getId()==null){
            return null;
        }
        //角色描述字数限制
        if(dto.getDescription().length()>50){
            return null;
        }
       Boolean modifyResult= iRoleService.modifyRole(dto);
        return null;
    }

    @GetMapping("/assign-menus")
    @ApiOperation(value = "角色分配菜单")
    @Override
    public JsonVO<Boolean> assignMenus(String roleId,String menuId) {
        return null;
    }

    @DeleteMapping("/delete-menus")
    @ApiOperation(value = "角色删除菜单")
    @Override
    public JsonVO<Boolean> deleteMenus(String roleId,String menuId) {
        return null;
    }

    @GetMapping("/assign-permissions")
    @ApiOperation(value = "角色分配权限")
    @Override
    public JsonVO<Boolean> assignPermissions(String roleId,String powerId) {
        return null;
    }

    @DeleteMapping("/delete-permissions")
    @ApiOperation(value = "角色删除权限")
    @Override
    public JsonVO<Boolean> deletePermissions(String roleId,String powerId) {
        return null;
    }

    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(String id) {
        return null;
    }
}

