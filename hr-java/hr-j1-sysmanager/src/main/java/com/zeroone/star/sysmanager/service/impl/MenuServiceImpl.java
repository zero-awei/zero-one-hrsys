package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.mapper.MenuMapper;
import com.zeroone.star.sysmanager.service.MenuService;
import org.springframework.stereotype.Service;

/**
 * The implementation of {@link MenuService}, base on {@link ServiceImpl}
 *
 * @author camille
 * @see MenuService
 * @see ServiceImpl
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements MenuService {
}
