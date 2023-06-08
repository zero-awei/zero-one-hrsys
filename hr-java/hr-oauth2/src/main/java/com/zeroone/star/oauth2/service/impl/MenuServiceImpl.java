package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.Menu;
import com.zeroone.star.oauth2.mapper.MenuMapper;
import com.zeroone.star.oauth2.service.IMenuService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements IMenuService {

    @Override
    public List<Menu> listAllLinkUrl() {
        QueryWrapper<Menu> wrapper = new QueryWrapper<>();
        wrapper.select("link_url");
        wrapper.isNotNull("link_url");
        return baseMapper.selectList(wrapper);
    }
}
