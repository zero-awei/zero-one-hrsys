package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.sysmanager.usermanager.UserConditionalQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.sysmanager.entity.User;
import com.zeroone.star.sysmanager.mapper.UserMapper;
import com.zeroone.star.sysmanager.service.IUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.apache.logging.log4j.util.Strings;
import org.springframework.stereotype.Service;
import org.springframework.validation.annotation.Validated;

import javax.annotation.Resource;
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


    @Resource
    UserHolder userHolder;
    @Override
    public PageDTO<UserDTO> listAllUsers(@Validated UserQuery query) {
        Page<User> page = new Page<>(query.getPageIndex(), query.getPageSize());

        LambdaQueryWrapper<User> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(Strings.isNotBlank(query.getId()), User::getId, query.getId());
        wrapper.eq(Strings.isNotBlank(query.getMail()), User::getMail, query.getMail());
        wrapper.eq(Strings.isNotBlank(query.getUsername()), User::getUsername, query.getUsername());
        wrapper.eq(Strings.isNotBlank(query.getPhone()), User::getPhone, query.getPhone());
        wrapper.eq(query.getRegistTime() != null, User::getRegistTime, query.getRegistTime());

        Page<User> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, UserDTO.class);
    }

    @Override
    public PageDTO<UserDTO> selectUser(UserConditionalQuery query) {
        Page<User> page = new Page<>(query.getPageIndex(), query.getPageSize());
        LambdaQueryWrapper<User> wrapper = new LambdaQueryWrapper<>();

        String condition = query.getCondition();
        wrapper.like(User::getId, condition).or()
                .like(User::getUsername, condition).or()
                .like(User::getPhone, condition).or()
                .like(User::getMail, condition).or()
                .like(User::getIsEnable, condition).or()
                .like(User::getRegistTime, condition);
        Page<User> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, UserDTO.class);
    }

    @Override
    public Boolean saveUser(UserDTO dto) {
        User user = new User();
        try {
            String username = userHolder.getCurrentUser().getUsername();
            BeanUtil.copyProperties(dto,user);
            LocalDateTime now = LocalDateTime.now();
            user.setRegistTime(now);
            user.setCreatetime(now);
            user.setCreator(username);
            return baseMapper.insert(user)>=1;
        } catch (Exception e) {
            return false;
        }
    }

    @Override
    public Boolean removeUser(String id) {
        return baseMapper.deleteById(id)>=1;
    }

    @Override
    public Boolean updateUser(UserDTO dto) {
        LambdaQueryWrapper<User> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(User::getId,dto.getId());
        User user = new User();
        BeanUtil.copyProperties(dto,user);
        return baseMapper.update(user,wrapper)>=1;
    }

    @Override
    public Boolean updateStatus(String id) {
        User user = baseMapper.selectById(id);
        Integer status = user.getIsEnable();
        status=(status+1)%2;
        user.setIsEnable(status);
        return baseMapper.updateById(user)>=1;
    }

}
