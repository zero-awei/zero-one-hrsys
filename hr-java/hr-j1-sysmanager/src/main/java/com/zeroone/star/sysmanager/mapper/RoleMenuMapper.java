package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.sysmanager.entity.RoleMenu;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface RoleMenuMapper {
    void assignMenus(RoleMenu roleMenu);

    void deleteMenus(RoleMenu roleMenu);
}