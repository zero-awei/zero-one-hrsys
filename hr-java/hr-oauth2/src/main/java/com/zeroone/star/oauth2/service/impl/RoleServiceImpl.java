package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.Power;
import com.zeroone.star.oauth2.entity.Role;
import com.zeroone.star.oauth2.mapper.RoleMapper;
import com.zeroone.star.oauth2.service.IRoleService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author 风月
 */
@Service
public class RoleServiceImpl extends ServiceImpl<RoleMapper, Role> implements IRoleService {

    @Override
    public List<Role> listRoleByUserId(int userId) {
        return baseMapper.selectByUserId(userId);
    }

    @Override
    public List<Role> listRoleByMenuPath(String path) {
        return baseMapper.selectByMenuPath(path);
    }
    @Override
    public List<Role> listRoleByPowerLinkUrl(String path) {
        return baseMapper.selectByPowerLinkUrl(path);
    }
}
