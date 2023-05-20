package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.sysmanager.entity.Role;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 角色表 服务类
 * </p>
 *
 * @author alan
 * @since 2023-05-20
 */
public interface IRoleService extends IService<Role> {
    RoleDTO getById(Integer id);

    String deleteById(Integer id);
}
