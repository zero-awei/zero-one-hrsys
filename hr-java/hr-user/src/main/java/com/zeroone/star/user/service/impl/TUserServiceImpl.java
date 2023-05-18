package com.zeroone.star.user.service.impl;

import com.zeroone.star.user.entity.TUser;
import com.zeroone.star.user.mapper.TUserMapper;
import com.zeroone.star.user.service.ITUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author axiao
 * @since 2023-05-18
 */
@Service
public class TUserServiceImpl extends ServiceImpl<TUserMapper, TUser> implements ITUserService {

}
