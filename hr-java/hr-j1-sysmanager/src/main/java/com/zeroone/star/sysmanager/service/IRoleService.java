package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.query.sysmanager.rolemanager.RoleQuery;
import com.zeroone.star.sysmanager.entity.Role;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 角色表 服务类
 * </p>
 *
 * @author Alan
 * @since 2023-05-28
 */
public interface IRoleService extends IService<Role> {
    /**
     * 查询一个角色
     * @param id
     * @return role
     */
    RoleDTO querRoleById(Integer id);

    /**
     * 通过id删除一个角色
     * @param id
     * @return boolean
     */
    Boolean deleRoleById(Integer id);

    /**
     * 新增一个角色
     * @param roleDTO
     * @return boolean
     */
    Boolean addRole(RoleDTO roleDTO);

    /**
     * 修改一个角色
     * @param roleDTO
     * @return boolean
     */
    Boolean modifyRole(RoleDTO roleDTO);

    /**
     * 修改角色状态
     * @param id
     * @return boolean
     */
    Boolean updateStatus(String id);

    PageDTO<RoleDTO> queryListRole(RoleQuery query);

}
