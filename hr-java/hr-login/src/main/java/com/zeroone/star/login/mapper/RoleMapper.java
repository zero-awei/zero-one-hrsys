package com.zeroone.star.login.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.Role;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 角色表 Mapper 接口
 * </p>
 *
 * @author 阿伟
 */
@Mapper
public interface RoleMapper extends BaseMapper<Role> {
    /**
     * 通过用户编号查询角色
     * @param userId 用户编号
     * @return 角色列表
     */
    List<Role> selectByUserId(String userId);

    /**
     * 通过菜单路径获取对应的角色
     * @param path 菜单路径
     * @return 角色列表
     */
    List<Role> selectByMenuPath(String path);
}
