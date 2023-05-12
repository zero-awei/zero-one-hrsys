package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

/**
 * <p>
 * 菜单 服务类
 * </p>
 * @author 阿伟
 */
public interface IMenuService extends IService<Menu> {
    /**
     * 通过角色名称获取，菜单资源
     * @param roleNames 角色名称
     * @return 返回菜单列表
     */
    List<MenuTreeVO> listMenuByRoleName(List<String> roleNames);
}
