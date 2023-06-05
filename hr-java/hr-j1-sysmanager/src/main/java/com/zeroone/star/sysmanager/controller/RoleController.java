package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.dto.sysmanager.rolemenumanager.RoleMenuDTO;
import com.zeroone.star.project.dto.sysmanager.rolepowermanager.RolePowerDTO;
import com.zeroone.star.project.sysmanager.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.RoleMenuService;
import com.zeroone.star.sysmanager.service.RolePowerService;
import com.zeroone.star.sysmanager.service.RoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 角色表 前端控制器
 * </p>
 *
 * @author alan、sleepea
 * @since 2023-05-20
 */

@RestController
@Api(tags = "角色管理")
@RequestMapping("/sys-role")
public class RoleController implements RoleApis {
    @Resource
    RoleService roleService;

    @Resource
    private RolePowerService rolePowerService;

    @Resource
    private RoleMenuService roleMenuService;

    @ApiOperation(value = "查看角色详情")
    @GetMapping("/query-one")
    @Override
    public JsonVO<RoleDTO> queryById(@ApiParam(value = "角色id", required = true, example = "1") @RequestParam String id) {
        return JsonVO.success(roleService.querRoleById(id));
    }

    @ApiOperation(value = "删除角色")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<Boolean> deleteRole(@ApiParam(value = "需删除的角色id", example = "2") @RequestParam String id) {
        boolean result = roleService.deleRoleById(id);
        if (result) {
            return JsonVO.success(true);
        } else {
            return JsonVO.fail(false);
        }

    }

    @ApiOperation(value = "增加角色")
    @PostMapping("/add-one")
    @Override
    public JsonVO<Boolean> addOneRole(RoleDTO dto) {
        if (dto.getDescription() == null &&
                dto.getName() == null &&
                dto.getKeyword() == null) {
            return JsonVO.fail(false);
        }
        Boolean addResult = roleService.addRole(dto);
        if (addResult) {
            return JsonVO.success(true);
        } else {
            return JsonVO.fail(false);
        }
    }

    @ApiOperation(value = "修改角色")
    @PostMapping("/modify")
    @Override
    public JsonVO<Boolean> modifyRole(RoleDTO dto) {
        //输入的id不能为空
        if (dto.getId() == null) {
            JsonVO.fail(false);
        }
        //角色描述字数限制
        if (dto.getDescription().length() > 50) {
            JsonVO.fail(false);
        }
        Boolean modifyResult = roleService.modifyRole(dto);
        if (modifyResult) {
            return JsonVO.success(true);
        } else {
            return JsonVO.fail(false);
        }
    }

    /**
     * @param dto 用户菜单对象
     * @return
     * @author sleepea
     */
    @PostMapping("/assign-menus")
    @ApiOperation(value = "角色分配菜单")
    @Override
    public JsonVO<Boolean> assignMenus(@RequestBody RoleMenuDTO dto) {
        JsonVO<Boolean> json = new JsonVO<>();
        try {
            // 查询相应的角色和菜单，以确保它们存在且可以被操作
            if (!roleMenuService.checkRoleMenu(dto)) {
                json.setData(false);
                json.setMessage("不存在此用户或者此菜单");
                return json;
            }
            // 检索指定角色的现有菜单 ID 列表
            List<String> existingMenuIds = roleMenuService.getMenuIdsByRoleId(dto.getRoleId());
            // 查看是否已存在此菜单ID
            if (existingMenuIds.contains(dto.getMenuId())) {
                json.setData(false);
                json.setMessage("当前用户已被分配此菜单");
                return json;
            }
            // 将新的菜单 ID 添加到用户菜单表中
            boolean result = roleMenuService.assignMenus(dto);
            // 返回结果
            json.setData(result);
            json.setMessage(result ? "分配菜单成功" : "分配菜单失败");
            return json;
        } catch (Exception e) {
            json.setData(false);
            json.setMessage("分配菜单失败");
            return json;
        }
    }

    /**
     * author sleepea
     *
     * @param dto 用户菜单对象
     * @return
     */
    @DeleteMapping("/delete-menus")
    @ApiOperation(value = "角色删除菜单")
    @Override
    public JsonVO<Boolean> deleteMenus(@RequestBody RoleMenuDTO dto) {
        JsonVO<Boolean> json = new JsonVO<>();
        try {
            // 查询相应的角色和菜单，以确保它们存在且可以被操作
            if (!roleMenuService.checkRoleMenu(dto)) {
                json.setData(false);
                json.setMessage("不存在此用户或者此菜单");
                return json;
            }
            // 检索指定角色的现有菜单 ID 列表
            List<String> existingMenuIds = roleMenuService.getMenuIdsByRoleId(dto.getRoleId());
            // 查看传入的菜单ID是否在现有菜单ID列表中
            if (!existingMenuIds.contains(dto.getMenuId())) {
                json.setData(false);
                json.setMessage("该用户不存在要删除的菜单");
                return json;
            }
            // 将此菜单 ID 从数据库中删除
            boolean result = roleMenuService.deleteMenus(dto);
            // 返回结果
            json.setData(result);
            json.setMessage(result ? "删除菜单成功" : "删除菜单失败");
            return json;
        } catch (Exception e) {
            json.setData(false);
            json.setMessage("删除菜单失败");
            return json;
        }
    }

    /**
     * @param dto 用户权限对象
     * @return
     * @author sleephea
     */
    @GetMapping("/assign-permissions")
    @ApiOperation(value = "角色分配权限")
    @Override
    public JsonVO<Boolean> assignPermissions(RolePowerDTO dto) {
        JsonVO<Boolean> json = new JsonVO<>();
        try {
            // 查询相应的角色和菜单，以确保它们存在且可以被操作
            if (!rolePowerService.checkRoleMenu(dto)) {
                json.setData(false);
                json.setMessage("不存在此用户或者此菜单");
                return json;
            }
            // 检索指定角色的现有权限 ID 列表
            List<String> existingPowerIds = rolePowerService.getPowerIdsByRoleId(dto.getPowerId());
            // 查看是否已存在此权限ID
            if (existingPowerIds.contains(dto.getPowerId())) {
                json.setData(false);
                json.setMessage("当前用户已被分配此权限");
                return json;
            }
            // 将新的权限 ID 添加到数据库中
            boolean result = rolePowerService.assignPermissions(dto);
            // 返回结果
            json.setData(result);
            json.setMessage(result ? "分配权限成功" : "分配权限失败");
            return json;
        } catch (Exception e) {
            json.setData(false);
            json.setMessage("分配权限失败");
            return json;
        }
    }

    /**
     * @param dto 用户权限对象
     * @return
     * @author sleephea
     */
    @DeleteMapping("/delete-permissions")
    @ApiOperation(value = "角色删除权限")
    @Override
    public JsonVO<Boolean> deletePermissions(RolePowerDTO dto) {
        JsonVO<Boolean> json = new JsonVO<>();
        try {
            // 查询相应的角色和菜单，以确保它们存在且可以被操作
            if (!rolePowerService.checkRoleMenu(dto)) {
                json.setData(false);
                json.setMessage("不存在此用户或者此菜单");
                return json;
            }
            // 检索指定角色的现有权限 ID 列表
            List<String> existingPowerIds = rolePowerService.getPowerIdsByRoleId(dto.getRoleId());
            // 查看传入的权限ID是否在现有权限ID列表中
            if (!existingPowerIds.contains(dto.getPowerId())) {
                json.setData(false);
                json.setMessage("该用户不存在要删除的权限");
                return json;
            }
            // 将此 权限ID 从数据库中删除
            boolean result = rolePowerService.deletePermissions(dto);
            // 返回结果
            json.setData(result);
            json.setMessage(result ? "删除权限成功" : "删除权限失败");
            return json;
        } catch (Exception e) {
            json.setData(false);
            json.setMessage("删除权限失败");
            return json;
        }
    }

    /**
     * 修改状态
     * @param id ID 用户id
     * @author sleephea
     */
    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(String id) {
        return roleService.updateStatus(id) ? JsonVO.success(true) : JsonVO.fail(false);
    }
}

