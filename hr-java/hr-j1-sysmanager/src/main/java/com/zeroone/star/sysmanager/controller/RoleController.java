package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.dto.sysmanager.rolemenumanager.RoleMenuDTO;
import com.zeroone.star.project.dto.sysmanager.rolepowermanager.RolePowerDTO;
import com.zeroone.star.project.sysmanager.RoleApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.RoleMenuService;
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

    @GetMapping("/query-one")
    @ApiOperation(value = "查看管理员详情")
    @Override
    public JsonVO<RoleDTO> queryById(String id) {
        return null;
    }
    @ApiOperation(value = "删除角色")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<Boolean> deleteRole(String id) {
        return null;
    }
    @ApiOperation(value = "增加角色")
    @PostMapping("/add-one")
    @Override
    public JsonVO<Boolean> addOneRole(RoleDTO dto) {
        return null;
    }
    @ApiOperation(value = "修改角色")
    @PutMapping("/modify")
    @Override
    public JsonVO<Boolean> modifyRole(RoleDTO dto) {
        return null;
    }
    @Resource
    private RoleMenuService roleMenuService;
    @GetMapping("/assign-menus")
    @ApiOperation(value = "角色分配菜单")
    @Override
    public JsonVO<Boolean> assignMenus(@RequestBody RoleMenuDTO dto) {
        JsonVO<Boolean> json = new JsonVO<>();
        try {
            // 查询相应的角色和菜单，以确保它们存在且可以被操作

            // 检索指定角色的现有菜单 ID 列表
            String existingMenuIds = roleMenuService.getMenuIdsByRoleId(dto.getRoleId());
            // 将新的菜单 ID 添加到现有的菜单 ID 列表中
            String updatedMenuIds = existingMenuIds + "," + dto.getMenuId();
            dto.setMenuId(updatedMenuIds);
            // 将更新后的菜单 ID 列表保存回数据库中
            boolean result = roleMenuService.assignMenus(dto);

            json.setData(result);
            json.setMessage("分配菜单成功");
            return json;
        }catch (Exception e) {
            json.setData(false);
            json.setMessage("分配菜单失败");
            return json;
        }
    }

    @DeleteMapping("/delete-menus")
    @ApiOperation(value = "角色删除菜单")
    @Override
    public JsonVO<Boolean> deleteMenus(@RequestBody RoleMenuDTO dto) {
        JsonVO<Boolean> json = new JsonVO<>();
        try {
            // 查询相应的角色和菜单，以确保它们存在且可以被操作

            // 检索指定角色的现有菜单 ID 列表
            String existingMenuIds = roleMenuService.getMenuIdsByRoleId(dto.getRoleId());
            // 查看传入的菜单ID是否在现有菜单ID列表中
            if(!existingMenuIds.contains(dto.getMenuId())){
                json.setData(false);
                json.setMessage("该用户不存在要删除的菜单");
                return json;
            }
            // 将此菜单 ID 从菜单 ID 列表中删除
            String[] parts = existingMenuIds.split(","); // 将字符串按逗号分割成数组

            StringBuilder sb = new StringBuilder();
            for (String part : parts) {
                if (!part.equals(dto.getMenuId())) {
                    sb.append(part).append(",");
                }
            }

            if (sb.length() > 0) {
                sb.setLength(sb.length() - 1); // 去掉最后一个逗号
            }
            // 新构建的 menuId
            dto.setMenuId(sb.toString());

            // 将更新后的菜单 ID 列表保存回数据库中
            boolean result = roleMenuService.deleteMenus(dto);

            json.setData(result);
            json.setMessage("删除菜单成功");
            return json;
        }catch (Exception e) {
            json.setData(false);
            json.setMessage("删除菜单失败");
            return json;
        }
    }
    @GetMapping("/assign-permissions")
    @ApiOperation(value = "角色分配权限")
    @Override
    public JsonVO<Boolean> assignPermissions(RolePowerDTO dto) {
        return null;
    }

    @DeleteMapping("/delete-permissions")
    @ApiOperation(value = "角色删除权限")
    @Override
    public JsonVO<Boolean> deletePermissions(RolePowerDTO dto) {
        return null;
    }

    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(String id) {
        return null;
    }
}

