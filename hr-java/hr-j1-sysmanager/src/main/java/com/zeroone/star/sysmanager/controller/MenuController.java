package com.zeroone.star.sysmanager.controller;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.bean.copier.CopyOptions;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.TableFieldInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfoHelper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.sysmanager.MenuApis;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.service.MenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Objects;

/**
 * The controller of {@link MenuApis}, base on {@link MenuService}
 *
 * @author camille
 * @see MenuApis
 * @see MenuService
 */

@RestController
@RequestMapping("/menu")
@Api(tags = "菜单管理")
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
    public JsonVO<PageDTO<MenuDTO>> queryAll(MenuQuery query) {
        long pageIndex = query.getPageIndex();
        long pageSize = query.getPageSize();
        Page<Menu> page = new Page<>(pageIndex, pageSize);
        // 构建查询条件
        LambdaQueryWrapper<Menu> queryWrapper = new LambdaQueryWrapper<>();
        String name = query.getName();
        if (Objects.nonNull(name)) {
            queryWrapper.eq(Menu::getName, name);
        }
        String path = query.getPath();
        if (Objects.nonNull(path)) {
            queryWrapper.eq(Menu::getPath, path);
        }
        Integer priority = query.getPriority();
        if (Objects.nonNull(priority)) {
            queryWrapper.eq(Menu::getPriority, priority);
        }
        String icon = query.getIcon();
        if (Objects.nonNull(icon)){
            queryWrapper.eq(Menu::getIcon, icon);
        }
        String description = query.getDescription();
        if (Objects.nonNull(description)){
            queryWrapper.eq(Menu::getDescription, description);
        }
        Integer parent_menu_id = query.getParent_menu_id();
        if (Objects.nonNull(parent_menu_id)){
            queryWrapper.eq(Menu::getParent_menu_id, parent_menu_id);
        }
        Integer isEnable = query.getIsEnable();
        if (Objects.nonNull(isEnable)) {
            queryWrapper.eq(Menu::getIsEnable, isEnable);
        }
        Integer level = query.getLevel();
        if (Objects.nonNull(level)) {
            queryWrapper.eq(Menu::getLevel, level);
        }
        // 执行分页查询
        Page<Menu> resultPage = menuService.page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, MenuDTO.class));
    }




    @ApiOperation(value = "增加菜单")
    @PostMapping("/add-menu")
    @Override
    public JsonVO<Boolean> addMenu(MenuDTO dto) {

        // 字段 id 为 varchar(64) 类型，不能设置为自增，需要自己指定
        // 判断 id 是否重复
        String id = dto.getId();
        Menu checkMenu = menuService.getById(id);
        if (Objects.nonNull(checkMenu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "id 重复");
        }
        // 判断 name 非空且不重复
        String name = dto.getName();
        boolean nameIsNullOrExist = Objects.isNull(name) ||
                Objects.nonNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getName, name)));
        if (nameIsNullOrExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "name 不能为空或已存在");
        }
        // 判断 path 非空且不重复
        String path = dto.getPath();
        boolean pathIsNullOrExist = Objects.isNull(path) ||
                Objects.nonNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getPath, path)));
        if (pathIsNullOrExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "path 不能为空或已存在");
        }
        // 判断 priority 是否存在
        Integer priority = dto.getPriority();
        boolean priorityNotExist = Objects.isNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getPriority,priority)));
        if(priorityNotExist){
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(),"priority 不存在");
        }
        // 判断 icon 是否存在
        String icon = dto.getIcon();
        boolean iconNotExist = Objects.isNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getIcon, icon)));
        if(iconNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "icon 不存在");
        }
        // 判断 parent_menu_id 是否存在
        String parent_menu_id = dto.getParent_menu_id();
        boolean parent_menu_idNotExist = Objects.isNull(menuService.getById(parent_menu_id));
        if (parent_menu_idNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent menu id 不存在");
        }
        // 将 dto 的非空属性赋值给 menu 权限，然后添加权限
        Menu menu = new Menu();
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = menuService.save(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @ApiOperation(value = "修改菜单")
    @PostMapping("/modify-menu")
    @Override
    public JsonVO<Boolean> modifyMenu(MenuDTO dto) {
        String id = dto.getId();
        Menu menu = menuService.getById(id);
        if (Objects.isNull(menu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        // 若修改了 name，则需判断 name 是否重复
        String name = dto.getName();
        boolean nameExist = !menu.getName().equals(name) &&
                Objects.nonNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getName, name)));
        if (nameExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "修改后的 name 已存在");
        }
        // 若修改了 path，则需判断 path 是否重复
        String path = dto.getPath();
        boolean pathExist = !menu.getPath().equals(path) &&
                Objects.nonNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getPath, path)));
        if (pathExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "修改后的 link url 已存在");
        }
        // 判断 icon 是否存在
        String icon = dto.getIcon();
        boolean iconNotExist = Objects.isNull(menuService.getOne(new QueryWrapper<Menu>().lambda().eq(Menu::getIcon, icon)));
        if(iconNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "icon 不存在");
        }
        // 判断 parent_menu_id 是否存在
        String parent_menu_id = dto.getParent_menu_id();
        boolean parent_menu_idNotExist = Objects.isNull(menuService.getById(parent_menu_id));
        if (parent_menu_idNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent menu id 不存在");
        }
        // 将 dto 的非空属性赋值给 menu 权限，然后更新权限
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = menuService.updateById(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @ApiOperation(value = "删除菜单")
    @DeleteMapping("/remove-menu")
    @Override
    public JsonVO<Boolean> removeMenu(String id) {
        if (Menu_ROOT_ID.equals(id)) {
            // 不能删除根权限
            return JsonVO.create(false, ResultStatus.FORBIDDEN.getCode(), "不能删除主菜单");
        }
        Menu menu = menuService.getById(id);
        if (Objects.isNull(menu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "菜单不存在");
        }
        boolean result = menuService.removeById(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @ApiOperation(value = "模糊查询")
    @GetMapping("/query-like")
    @Override
    public JsonVO<PageDTO<MenuDTO>> queryLike(CommentQuery query) {
        long pageIndex = query.getPageIndex();
        long pageSize = query.getPageSize();
        Page<Menu> page = new Page<>(pageIndex, pageSize);
        // 构建查询条件
        String queryLike = query.getQuery();
        QueryWrapper<Menu> queryWrapper = new QueryWrapper<>();
        TableInfo tableInfo = TableInfoHelper.getTableInfo(Menu.class);
        List<TableFieldInfo> fieldList = tableInfo.getFieldList();
        for (TableFieldInfo field : fieldList) {
            queryWrapper.or(wrapper -> wrapper.like(field.getColumn(), queryLike));
        }
        // 执行分页查询
        Page<Menu> resultPage = menuService.page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, MenuDTO.class));
    }

    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(String id) {
        Menu menu = menuService.getById(id);
        if (Objects.isNull(menu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "菜单不存在");
        }
        Integer isEnable = menu.getIsEnable();
        if (Objects.isNull(isEnable)) {
            // 若 isEnable 为空说明数据库有脏数据
            return JsonVO.create(false, ResultStatus.SERVER_ERROR.getCode(), "数据库字段数据异常");
        }
        if (isEnable.equals(1)) {
            menu.setIsEnable(0);
        } else {
            menu.setIsEnable(1);
        }
        boolean result = menuService.updateById(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }
}