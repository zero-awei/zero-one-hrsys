package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.User;
import com.zeroone.star.login.mapper.UserMapper;
import com.zeroone.star.login.service.IUserService;
import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * @author 风月
 * @date 2023/5/15 10:00
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {


    @Override
    public String getCurrentPassword(String username) {
        LambdaQueryWrapper<User> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.eq(User::getUsername, username);
        User user = baseMapper.selectOne(lambdaQueryWrapper);
        return user.getPassword();
    }

    @Override
    public Boolean updatePassword(String username, String password) {
        User user = new User();
        user.setUsername(username);
        user.setPassword(password);
        UpdateWrapper<User> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("username", username);
        int updateNum = baseMapper.update(user, updateWrapper);
        return updateNum == 1;
    }
}
