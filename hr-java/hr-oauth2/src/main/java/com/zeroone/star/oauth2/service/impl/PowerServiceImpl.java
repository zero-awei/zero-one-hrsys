package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.Menu;
import com.zeroone.star.oauth2.entity.Power;
import com.zeroone.star.oauth2.mapper.PowerMapper;
import com.zeroone.star.oauth2.service.IPowerService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * 权限服务实现类
 *
 * @author 风月
 * @date 2023/5/31 19:44
 */
@Service
public class PowerServiceImpl extends ServiceImpl<PowerMapper, Power> implements IPowerService {
    @Override
    public List<Power> listAllLinkUrl() {
        QueryWrapper<Power> wrapper = new QueryWrapper<>();
        wrapper.select("link_url");
        wrapper.isNotNull("link_url");
        return baseMapper.selectList(wrapper);

    }
}
