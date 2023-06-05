package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.sysmanager.rolepowermanager.RolePowerDTO;
import com.zeroone.star.sysmanager.mapper.RolePowerMapper;
import com.zeroone.star.sysmanager.service.RolePowerService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;
/**
 * The implementation of {@link RolePowerService}, base on {@link ServiceImpl}
 *
 * @author sleephea
 * @see RolePowerService
 * @see ServiceImpl
 */
@Service
public class RolePowerServiceImpl implements RolePowerService {
    @Resource
    private RolePowerMapper rolePowerMapper;
    @Override
    @Transactional
    public Boolean assignPermissions(RolePowerDTO dto) {
        return rolePowerMapper.assignPower(dto.getRoleId(), dto.getPowerId()) > 0;
    }

    @Override
    @Transactional
    public Boolean deletePermissions(RolePowerDTO dto) {
        return rolePowerMapper.deletePower(dto.getRoleId(), dto.getPowerId()) > 0;
    }

    @Override
    @Transactional
    public List<String> getPowerIdsByRoleId(String roleId) {
        return rolePowerMapper.getPowerIdsByRoleId(roleId);
    }

    @Override
    public Boolean checkRoleMenu(RolePowerDTO dto) {
        return rolePowerMapper.checkRolePower(dto.getRoleId(), dto.getPowerId()) > 0;
    }
}
