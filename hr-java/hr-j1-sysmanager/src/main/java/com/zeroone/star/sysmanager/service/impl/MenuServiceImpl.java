package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.bean.copier.CopyOptions;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.TableFieldInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfoHelper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.mapper.MenuMapper;
import com.zeroone.star.sysmanager.service.MenuService;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Objects;

/**
 * The implementation of {@link MenuService}, base on {@link ServiceImpl}
 *
 * @author camille
 * @see MenuService
 * @see ServiceImpl
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements MenuService {



    private static final String Menu_ROOT_ID = "0";


    //分页查询
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
        Page<Menu> resultPage = page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, MenuDTO.class));
    }


    //新增菜单
    @Override
    public JsonVO<Boolean> addMenu(MenuDTO dto) {

        // 字段 id 为 varchar(64) 类型，不能设置为自增，需要自己指定
        // 判断 id 是否重复
        String id = dto.getId();
        Menu checkMenu = getById(id);
        if (Objects.nonNull(checkMenu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "id 重复");
        }
        // 判断 priority 是否存在
        Integer priority = dto.getPriority();
        boolean priorityNotExist = Objects.isNull(getById(priority));
        if(priorityNotExist){
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(),"priority 不存在");
        }
        // 判断 icon 是否存在
        String icon = dto.getIcon();
        boolean iconNotExist = Objects.isNull(getById(icon));
        if(iconNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "icon 不存在");
        }
        // 判断 parent_menu_id 是否存在
        String parent_menu_id = dto.getParent_menu_id();
        boolean parent_menu_idNotExist = Objects.isNull(getById(parent_menu_id));
        if (parent_menu_idNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent menu id 不存在");
        }
        // 将 dto 的非空属性赋值给 menu 权限，然后添加权限
        Menu menu = new Menu();
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = save(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }



    //修改菜单
    @Override
    public JsonVO<Boolean> modifyMenu(MenuDTO dto) {
        String id = dto.getId();
        Menu menu = getById(id);
        if (Objects.isNull(menu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        // 判断 icon 是否存在
        String icon = dto.getIcon();
        boolean iconNotExist = Objects.isNull(getById(icon));
        if(iconNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "icon 不存在");
        }
        // 判断 parent_menu_id 是否存在
        String parent_menu_id = dto.getParent_menu_id();
        boolean parent_menu_idNotExist = Objects.isNull(getById(parent_menu_id));
        if (parent_menu_idNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent menu id 不存在");
        }
        // 将 dto 的非空属性赋值给 menu 权限，然后更新权限
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = updateById(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }


    //删除菜单

    @Override
    public JsonVO<Boolean> removeMenu(String id) {
        if (Menu_ROOT_ID.equals(id)) {
            // 不能删除根权限
            return JsonVO.create(false, ResultStatus.FORBIDDEN.getCode(), "不能删除主菜单");
        }
        Menu menu = getById(id);
        if (Objects.isNull(menu)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "菜单不存在");
        }
        boolean result = removeById(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }


    //模糊查询

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
        Page<Menu> resultPage = page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, MenuDTO.class));
    }


    //修改状态
    @Override
    public JsonVO<Boolean> modifyStatus(String id) {
        Menu menu = getById(id);
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
        boolean result = updateById(menu);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }
}
