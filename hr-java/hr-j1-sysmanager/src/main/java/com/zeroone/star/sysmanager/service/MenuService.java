package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.service.impl.MenuServiceImpl;

import java.util.List;


/**
 * The service interface for {@link Menu}, base on {@link IService}
 *
 * @author camille
 * @see IService
 * @see MenuServiceImpl
 */
public interface MenuService extends IService<Menu> {
    JsonVO<PageDTO<MenuDTO>> queryAll(MenuQuery query);

    JsonVO<Boolean> addMenu(MenuDTO dto);

    JsonVO<Boolean> modifyMenu(MenuDTO dto);

    JsonVO<Boolean> removeMenu(String id);

    JsonVO<PageDTO<MenuDTO>> queryLike(CommentQuery query);

    JsonVO<Boolean> modifyStatus(String id);

    /**
     * 通过角色名称获取，菜单资源
     * @param roleNames 角色名称
     * @return 返回菜单列表
     */
    List<MenuTreeVO> listMenuByRoleName(List<String> roleNames);

    String addMenuByTest(MenuDTO menuDTO);
}
