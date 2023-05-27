package com.zeroone.star.sysmanager.service.impl;

import com.zeroone.star.project.dto.sysmanager.rolepowermanager.RolePowerDTO;
import com.zeroone.star.sysmanager.mapper.RoleMenuMapper;
import com.zeroone.star.sysmanager.mapper.RolePowerMapper;
import com.zeroone.star.sysmanager.service.RolePowerService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class RolePowerServiceImpl implements RolePowerService {
    @Resource
    private RolePowerMapper rolePowerMapper;
    @Override
    public Boolean assignPermissions(RolePowerDTO dto) {
        return rolePowerMapper.assignPower(dto.getRoleId(), dto.getPowerId()) > 0;
    }

    @Override
    public Boolean deletePermissions(RolePowerDTO dto) {
        return rolePowerMapper.deletePower(dto.getRoleId(), dto.getPowerId()) > 0;
    }

    @Override
    public List<String> getPowerIdsByRoleId(String roleId) {
        return rolePowerMapper.getPowerIdsByRoleId(roleId);
    }
}
