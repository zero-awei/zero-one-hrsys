package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.query.sysmanager.rolemanager.RoleQuery;
import com.zeroone.star.sysmanager.entity.Role;
import com.zeroone.star.sysmanager.mapper.RoleMapper;
import com.zeroone.star.sysmanager.service.IRoleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Date;
import java.util.Objects;

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author Alan
 * @since 2023-05-28
 */
@Mapper(componentModel = "spring")
interface MsRoleMapper {
    /**
     * sample do 转换 role dto
     * @param role do对象
     * @return dto对象
     */
    RoleDTO roleToRoleDto(Role role);
}

@Service
public class RoleServiceImpl extends ServiceImpl<RoleMapper, Role> implements IRoleService {
    @Resource
    MsRoleMapper msRoleMapper;

    @Override
    public RoleDTO querRoleById(Integer id) {
        Role role = baseMapper.selectById(id);
        if (role == null) {
            return null;
        }

        return msRoleMapper.roleToRoleDto(role);
    }

    @Override
    public Boolean deleRoleById(Integer id) {
        int result = baseMapper.deleteById(id);
        return result == 1;
    }

    @Override
    public Boolean addRole(RoleDTO roleDTO) {

        Role role = new Role();
        role.setId(Integer.valueOf(roleDTO.getId()));
        role.setName(roleDTO.getName());
        role.setKeyword(roleDTO.getKeyword());
        role.setDescription(roleDTO.getDescription());
        role.setIsEnable(roleDTO.getIsEnable());
        //角色创建者
        role.setCreator(roleDTO.getCreator());


        int result = baseMapper.insert(role);


        return result == 1;
    }

    @Override
    public Boolean modifyRole(RoleDTO roleDTO) {
        Role role = new Role();
        role.setId(Integer.valueOf(roleDTO.getId()));
        role.setName(roleDTO.getName());
        role.setKeyword(roleDTO.getKeyword());
        role.setDescription(roleDTO.getDescription());
        role.setIsEnable(roleDTO.getIsEnable());
        UpdateWrapper<Role> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("name", roleDTO.getName());
        int updateNum = baseMapper.update(role, updateWrapper);

        return updateNum != 0;

    }

    @Override
    public Boolean updateStatus(String id) {
        Role role = baseMapper.selectById(id);
        Integer status = role.getIsEnable();
        status = (status + 1) % 2;
        role.setIsEnable(status);
        return baseMapper.updateById(role) >= 1;
    }

    @Override
    public PageDTO<RoleDTO> queryListRole(RoleQuery query) {
        //创建分页参数
        long pageIndex = query.getPageIndex();
        long pageSize = query.getPageSize();
        Page<Role> page = new Page<>(pageIndex, pageSize);
        //构建查询条件
        LambdaQueryWrapper<Role> queryWrapper = new LambdaQueryWrapper<>();
        String roleName = query.getName();

        if (Objects.nonNull(roleName)) {
            queryWrapper.eq(Role::getName, roleName);
        }
        String keyword = query.getKeyWord();
        if (Objects.nonNull(keyword)) {
            queryWrapper.eq(Role::getKeyword, keyword);
        }
        Integer isEnable = query.getIsEnable();
        if (Objects.nonNull(isEnable)) {
            queryWrapper.eq(Role::getIsEnable, isEnable);
        }
        //执行分页查询
        Page<Role> rolePage = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(rolePage, RoleDTO.class);
    }

}
