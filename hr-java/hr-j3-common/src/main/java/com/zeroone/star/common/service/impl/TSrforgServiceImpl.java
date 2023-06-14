package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.entity.TSrforg;
import com.zeroone.star.common.mapper.TSrforgMapper;
import com.zeroone.star.common.service.ITSrforgService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 组织机构 服务实现类
 * </p>
 *
 * @author tomcatcc
 * @since 2023-06-09
 */
@Service
public class TSrforgServiceImpl extends ServiceImpl<TSrforgMapper, TSrforg> implements ITSrforgService {

    @Autowired
    private TSrforgMapper mapper;
    @Override
    public List<String> queryOrganizationName(String id) {
        return mapper.queryOrganizationName(id);
    }
}
