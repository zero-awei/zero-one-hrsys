package com.zeroone.star.sysmanager.service.impl;

import com.zeroone.star.project.dto.sysmanager.rolemenumanager.RoleMenuDTO;
import com.zeroone.star.sysmanager.mapper.RoleMenuMapper;
import com.zeroone.star.sysmanager.service.RoleMenuService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;

@Service
public class RoleMenuServiceImpl implements RoleMenuService {
    @Resource
    private RoleMenuMapper roleMenuMapper;
    @Override
    @Transactional
    public Boolean assignMenus(RoleMenuDTO dto) {
        // 调用mapper层的assignMenu方法来将菜单ID添加到角色的菜单列表中
        return roleMenuMapper.assignMenu(dto.getRoleId(), dto.getMenuId()) > 0;
    }

    @Override
    @Transactional
    public Boolean deleteMenus(RoleMenuDTO dto) {
        // 调用mapper层的deleteMenu方法来从角色的菜单列表中删除菜单ID
        return roleMenuMapper.deleteMenu(dto.getRoleId(), dto.getMenuId()) > 0;
    }
    @Override
    @Transactional
    public List<String> getMenuIdsByRoleId(String roleId){
        // 调用mapper层的getMenuIdsByRoleId方法来从角色的菜单列表中获取已有的menuId
        return roleMenuMapper.getMenuIdsByRoleId(roleId);
    }

}
