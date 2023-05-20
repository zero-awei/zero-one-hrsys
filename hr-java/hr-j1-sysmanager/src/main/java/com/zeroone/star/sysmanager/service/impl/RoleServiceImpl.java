package com.zeroone.star.sysmanager.service.impl;

import com.sun.net.httpserver.Authenticator;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.sysmanager.entity.Role;
import com.zeroone.star.sysmanager.mapper.RoleMapper;
import com.zeroone.star.sysmanager.service.IRoleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsRoleMapper {
    /**
     * sample do 转换 sample dto
     * @param role do对象
     * @return dto对象
     */
    RoleDTO roleToRoleDto(Role role);
}

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author alan
 * @since 2023-05-20
 */
@Service
public class RoleServiceImpl extends ServiceImpl<RoleMapper, Role> implements IRoleService {
    @Resource
    MsRoleMapper msRoleMapper;

    @Override
    public RoleDTO getById(Integer id) {
        Role role = baseMapper.selectById(id);
        if (role==null){
            return null;
        }
        return msRoleMapper.roleToRoleDto(role);
    }

    /**
     * 删除角色
     * @param id
     * @return
     */
    @Override
    public String deleteById(Integer id) {
        baseMapper.deleteById(id);
        return "success" ;
    }
}
