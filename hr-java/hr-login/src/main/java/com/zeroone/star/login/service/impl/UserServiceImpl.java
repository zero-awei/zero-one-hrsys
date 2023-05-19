package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.User;
import com.zeroone.star.login.mapper.UserMapper;
import com.zeroone.star.login.service.IUserService;
import org.springframework.stereotype.Service;

/**
 * @author 风月
 * @date 2023/5/15 10:00
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {


    @Override
    public String getCurrentPassword(String username) {
        //TODO 待实现
        return null;
    }

    @Override
    public Boolean updatePassword(String username, String password) {
        //TODO 待实现
        return null;
    }
}
