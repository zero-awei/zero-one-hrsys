package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.Role;
import com.zeroone.star.login.mapper.RoleMapper;
import com.zeroone.star.login.service.IRoleService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class RoleServiceImpl extends ServiceImpl<RoleMapper, Role> implements IRoleService {

    @Override
    public List<Role> listRoleByUserId(String userId) {
        return baseMapper.selectByUserId(userId);
    }

    @Override
    public List<Role> listRoleByMenuPath(String path) {
        return baseMapper.selectByMenuPath(path);
    }
}
