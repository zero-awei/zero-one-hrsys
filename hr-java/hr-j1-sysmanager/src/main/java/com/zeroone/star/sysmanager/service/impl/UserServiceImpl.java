package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.sysmanager.entity.User;
import com.zeroone.star.sysmanager.mapper.UserMapper;
import com.zeroone.star.sysmanager.service.IUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.apache.logging.log4j.util.Strings;
import org.springframework.stereotype.Service;
import org.springframework.validation.annotation.Validated;

import java.time.LocalDateTime;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author axiao
 * @since 2023-05-25
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {


    @Override
    public PageDTO<UserDTO> listAllUsers(@Validated PageQuery pageInfo) {
        Page<User> page = new Page<>(pageInfo.getPageIndex(),pageInfo.getPageSize());
        Page<User> result = baseMapper.selectPage(page, new QueryWrapper<>());
        return PageDTO.create(result,UserDTO.class);
    }

    @Override
    public PageDTO<UserDTO> selectUser(UserQuery query) {
        Page<User> page = new Page<>(query.getPageIndex(),query.getPageSize());
        LambdaQueryWrapper<User> wrapper = new LambdaQueryWrapper<>();

        wrapper.like(Strings.isNotBlank(query.getId()),User::getId,query.getId());
        wrapper.like(Strings.isNotBlank(query.getMail()),User::getMail,query.getMail());
        wrapper.like(Strings.isNotBlank(query.getUsername()),User::getUsername,query.getUsername());
        wrapper.like(Strings.isNotBlank(query.getPhone()),User::getPhone,query.getPhone());
        wrapper.like(query.getRegistTime()!=null,User::getRegistTime,query.getRegistTime());
        Page<User> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result,UserDTO.class);
    }

    @Override
    public Boolean saveUser(UserDTO dto) {
        User user = new User();
        BeanUtil.copyProperties(dto,user);
        LocalDateTime now = LocalDateTime.now();
        user.setRegistTime(now);
        return baseMapper.insert(user)>=1;
    }
}
