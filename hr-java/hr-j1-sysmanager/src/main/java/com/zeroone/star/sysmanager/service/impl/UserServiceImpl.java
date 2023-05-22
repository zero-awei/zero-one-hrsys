package com.zeroone.star.sysmanager.service.impl;

import com.zeroone.star.sysmanager.entity.User;
import com.zeroone.star.sysmanager.mapper.UserMapper;
import com.zeroone.star.sysmanager.service.IUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author axiao
 * @since 2023-05-22
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User> implements IUserService {

}
