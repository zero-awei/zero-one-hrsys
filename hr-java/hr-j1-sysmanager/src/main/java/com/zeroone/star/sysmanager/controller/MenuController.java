package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.sysmanager.MenuApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.MenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;


/**
 * The controller of {@link MenuApis}, base on {@link MenuService}
 *
 * @author camille
 * @see MenuApis
 * @see MenuService
 */

@RestController
@RequestMapping("/sys-menu")
@Api(tags = "菜单管理")
@Validated
public class MenuController implements MenuApis {
    private MenuService menuService;

    private static final String Menu_ROOT_ID = "0";

    public MenuController(MenuService menuService) {
        this.menuService = menuService;
    }

    /**
     * 分页查询列表
     *
     * @param query 查询条件
     * @return 查询结果
     */
    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<MenuDTO>> queryAll(@Validated MenuQuery query) {
        return menuService.queryAll(query);
    }


    @ApiOperation(value = "增加菜单")
    @PostMapping("/add-menu")
    @Override
    public JsonVO<Boolean> addMenu(MenuDTO dto) {
        return menuService.addMenu(dto);
    }

    @ApiOperation(value = "修改菜单")
    @PostMapping("/modify-menu")
    @Override
    public JsonVO<Boolean> modifyMenu(MenuDTO dto) {
        return menuService.modifyMenu(dto);
    }

    @ApiOperation(value = "删除菜单")
    @DeleteMapping("/remove-menu")
    @Override
    public JsonVO<Boolean> removeMenu(@RequestParam String id) {
        return menuService.removeMenu(id);
    }

    @ApiOperation(value = "模糊查询")
    @GetMapping("/query-like")
    @Override
    public JsonVO<PageDTO<MenuDTO>> queryLike(CommentQuery query) {
        return menuService.queryLike(query);
    }

    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(@RequestParam String id) {
        return menuService.modifyStatus(id);
    }
}