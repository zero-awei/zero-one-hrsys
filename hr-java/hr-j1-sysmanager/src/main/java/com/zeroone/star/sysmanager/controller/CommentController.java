package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.query.sysmanager.rolemanager.RoleQuery;
import com.zeroone.star.project.sysmanager.CommentApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.IRoleService;
import com.zeroone.star.sysmanager.service.MenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/comment")
@Api(tags = "相同接口")
public class CommentController implements CommentApis {

    @Resource
    private IRoleService roleService;


    @Resource
    private MenuService menuService;

    @ApiOperation(value = "查询菜单结构树")
    @GetMapping("/query-menu-tree")
    @Override
    public JsonVO<List<MenuDTO>> queryMenuTree(@RequestParam String userId) {
        /*List<String> roleIds = userRoleService.getRoleIdsByUserId(userId);
        List<Menu> menus = new ArrayList<>();
        for (String roleId : roleIds) {
            Menu menu = menuService.getById(roleId);
            menus.add(menu);
        }
        return JsonVO.success(menus);*/
        return null;
    }

    @ApiOperation(value = "查询权限结构树")
    @GetMapping("/query-right-tree")
    @Override
    public JsonVO<List<RightDTO>> queryRightTree(@RequestParam String userId) {
        return null;
    }

    @ApiOperation(value = "分页查询角色列表")
    @GetMapping("/query-list-role")
    @Override
    public JsonVO<PageDTO<RoleDTO>> queryListRole(RoleQuery query) {
        return JsonVO.success(roleService.queryListRole(query));
    }

}
