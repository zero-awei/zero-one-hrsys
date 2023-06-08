package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.bean.copier.CopyOptions;
import cn.hutool.core.lang.Snowflake;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.TableFieldInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfoHelper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.mapper.MenuMapper;
import com.zeroone.star.sysmanager.service.MenuService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Objects;

/**
 * The implementation of {@link MenuService}, base on {@link ServiceImpl}
 *
 * @author camille
 * @see MenuService
 * @see ServiceImpl
 */

class MenuTreeNodMapper implements TreeNodeMapper<Menu> {
    @Override
    public TreeNode objectMapper(Menu menu) {
        MenuTreeVO treeNode = new MenuTreeVO();
        // 首先设置TreeNode计算层数使用属性
        treeNode.setTnId(menu.getId().toString());
        if (menu.getParent_menu_id() == null) {
            treeNode.setTnPid(null);
        } else {
            treeNode.setTnPid(menu.getParent_menu_id().toString());
        }
        // 设置扩展属性
        treeNode.setId(menu.getId());
        treeNode.setIcon(menu.getIcon());
        treeNode.setText(menu.getName());
        treeNode.setHref(menu.getPath());
        treeNode.setPid(menu.getParent_menu_id());
        return treeNode;
    }
}

@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements MenuService {

    @Resource
    private Snowflake snowflake;

    @Resource
    private UserHolder userHolder;

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
        if (Objects.nonNull(icon)) {
            queryWrapper.eq(Menu::getIcon, icon);
        }
        String description = query.getDescription();
        if (Objects.nonNull(description)) {
            queryWrapper.eq(Menu::getDescription, description);
        }
        Integer parent_menu_id = query.getParent_menu_id();
        if (Objects.nonNull(parent_menu_id)) {
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
        System.out.println(JsonVO.success(PageDTO.create(resultPage, MenuDTO.class)));
        return JsonVO.success(PageDTO.create(resultPage, MenuDTO.class));
    }


    //新增菜单
    @Override
    public JsonVO<Boolean> addMenu(MenuDTO dto) {
        // 判断 parent_menu_id 是否存在
        String parent_menu_id = dto.getParent_menu_id();
        boolean parent_menu_idNotExist = Objects.isNull(getById(parent_menu_id));
        if (parent_menu_idNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent menu id 不存在");
        }
        // 将 dto 的非空属性赋值给 menu 权限，然后添加权限
        Menu menu = new Menu();
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        menu.setId(String.valueOf(snowflake.nextId()));
        try {
            menu.setCreator(userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        Date date = new Date(System.currentTimeMillis());
        menu.setCreateTime(date);
        menu.setUpdateTime(date);
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
        // 判断 parent_menu_id 是否存在
        String parent_menu_id = dto.getParent_menu_id();
        boolean parent_menu_idNotExist = Objects.isNull(getById(parent_menu_id));
        if (parent_menu_idNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent menu id 不存在");
        }
        // 将 dto 的非空属性赋值给 menu 权限，然后更新权限
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        menu.setUpdateTime(new Date(System.currentTimeMillis()));
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

    @Override
    public List<MenuTreeVO> listMenuByRoleName(List<String> roleNames) {
        //1 定义一个存储数据库查询菜单数据的容器
        List<Menu> menus = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<Menu> tMenus = baseMapper.selectByRoleName(roleName);
            if (tMenus != null && !tMenus.isEmpty()) {
                menus.addAll(tMenus);
            }
        });
        //3 转换树形结构并返回
        return TreeUtils.listToTree(menus, new MenuTreeNodMapper());
    }

    @Override
    public String addMenuByTest(MenuDTO dto) {
        // 将 dto 的非空属性赋值给 menu 权限，然后添加权限
        Menu menu = new Menu();
        BeanUtil.copyProperties(dto, menu, CopyOptions.create().setIgnoreNullValue(true));
        String id = String.valueOf(snowflake.nextId());
        menu.setId(id);
        menu.setCreator("admin");
        Date date = new Date(System.currentTimeMillis());
        menu.setCreateTime(date);
        menu.setUpdateTime(date);
        boolean result = save(menu);
        return id;
    }
}
