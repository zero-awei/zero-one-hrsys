package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.query.sysmanager.rolemanager.RoleQuery;
import com.zeroone.star.sysmanager.entity.Role;
import com.zeroone.star.sysmanager.service.impl.RoleServiceImpl;

/**
 * The service interface for {@link Role}, base on {@link IService}
 *
 * @author Alan
 * @see IService
 * @see RoleServiceImpl
 */
public interface RoleService extends IService<Role> {

    RoleDTO querRoleById(String id);


    Boolean deleRoleById(String id);


    Boolean addRole(RoleDTO roleDTO);


    Boolean modifyRole(RoleDTO roleDTO);


    Boolean updateStatus(String id);

    PageDTO<RoleDTO> queryListRole(RoleQuery query);

}
