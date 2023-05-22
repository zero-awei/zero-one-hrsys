package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.sysmanager.MenuApis;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */

@RestController
@RequestMapping("/menu")
@Api(tags = "菜单管理")
public class MenuController implements MenuApis {
    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<MenuDTO>> queryAll(MenuQuery query) {
        return null;
    }

    @ApiOperation(value = "增加菜单")
    @PostMapping("/add-right")
    @Override
    public JsonVO<Boolean> addMenu(MenuDTO dto) {
        return null;
    }

    @ApiOperation(value = "修改菜单")
    @PostMapping("/modify-right")
    @Override
    public JsonVO<Boolean> modifyMenu(MenuDTO dto) {
        return null;
    }

    @ApiOperation(value = "删除菜单")
    @DeleteMapping("/remove-right")
    @Override
    public JsonVO<Boolean> removeMenu(MenuDTO dto) {
        return null;
    }

    @ApiOperation(value = "模糊查询")
    @GetMapping("/query-like")
    @Override
    public JsonVO<PageDTO<MenuDTO>> queryLike(MenuQuery query) {
        return null;
    }
}