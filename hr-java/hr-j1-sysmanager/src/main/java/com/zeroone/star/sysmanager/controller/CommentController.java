package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.query.sysmanager.rolemanager.RoleQuery;
import com.zeroone.star.project.sysmanager.CommentApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.project.vo.sysmanager.RightTreeVO;
import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.service.MenuService;
import com.zeroone.star.sysmanager.service.RightService;
import com.zeroone.star.sysmanager.service.RoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 相同接口 前端控制器
 * </p>
 * @author naturezh
 */
@RestController
@RequestMapping("/sys-comment")
@Api(tags = "相同接口")
public class CommentController implements CommentApis {

    @Resource
    private RoleService roleService;

    @Resource
    private UserHolder userHolder;

    @Resource
    private MenuService menuService;

    @Resource
    private RightService rightService;

    @ApiOperation(value = "查询菜单结构树")
    @GetMapping("/query-menu-tree")
    @Override
    public JsonVO<List<MenuTreeVO>>queryMenuTree() {
        //1 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        //2 获取当前用户拥有的菜单
        List<MenuTreeVO> menus = menuService.listMenuByRoleName(currentUser.getRoles());
        return JsonVO.success(menus);
    }

    @ApiOperation(value = "查询权限结构树")
    @GetMapping("/query-right-tree")
    @Override
    public JsonVO<List<RightTreeVO>>queryRightTree() {
        //1 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        //2 获取当前用户拥有的权限
        List<RightTreeVO> rights = rightService.listRightByRoleName(currentUser.getRoles());
        return JsonVO.success(rights);
    }

    @ApiOperation(value = "分页查询角色列表")
    @GetMapping("/query-list-role")
    @Override
    public JsonVO<PageDTO<RoleDTO>> queryListRole(RoleQuery query) {
        return JsonVO.success(roleService.queryListRole(query));
    }
}
