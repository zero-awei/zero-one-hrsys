package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.TOrmorginfo;
import com.zeroone.star.orgmanager.mapper.TOrmorginfoMapper;
import com.zeroone.star.orgmanager.service.ITOrmorginfoService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 组织信息 服务实现类
 * </p>
 *
 * @author H
 * @since 2023-05-30
 */
@Service
public class TOrmorginfoServiceImpl extends ServiceImpl<TOrmorginfoMapper, TOrmorginfo> implements ITOrmorginfoService {


    @Override
    public boolean deleteOrg(List<String> orgIds) {
        return baseMapper.deleteBatchIds(orgIds)!=0?false:true;
    }
}
