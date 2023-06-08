package com.zeroone.star.login.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.Role;

import java.util.List;

/**
 * <p>
 * 角色表 服务类
 * </p>
 *
 * @author 阿伟
 */
public interface IRoleService extends IService<Role> {
    /**
     * 通过用户编号获取角色列表
     * @param userId 用户编号
     * @return 角色列表
     */
    List<Role> listRoleByUserId(String userId);

    /**
     * 获取指定菜单路径有访问权限的角色
     * @param path 指定菜单路径
     * @return 角色列表
     */
    List<Role> listRoleByMenuPath(String path);
}
