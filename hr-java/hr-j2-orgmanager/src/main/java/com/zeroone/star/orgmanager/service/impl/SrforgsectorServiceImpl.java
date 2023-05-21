package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.orgmanager.mapper.SrforgsectorMapper;
import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 组织部门 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
public class SrforgsectorServiceImpl extends ServiceImpl<SrforgsectorMapper, Srforgsector> implements ISrforgsectorService {
    @Resource
    private SrforgsectorMapper srforgsectorMapper;
    @Override
    public Boolean removeDeptById(String id) {
        if (srforgsectorMapper.deleteById(id) >0) {
            return true;
        }
        return false;
    }
}
