package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.sysmanager.entity.Right;
import com.zeroone.star.sysmanager.mapper.RightMapper;
import com.zeroone.star.sysmanager.service.RightService;
import org.springframework.stereotype.Service;

/**
 * The implementation of {@link RightService}, base on {@link ServiceImpl}
 *
 * @author authoralankay
 * @see RightService
 * @see ServiceImpl
 */
@Service
public class RightServiceImpl extends ServiceImpl<RightMapper, Right> implements RightService {
}
