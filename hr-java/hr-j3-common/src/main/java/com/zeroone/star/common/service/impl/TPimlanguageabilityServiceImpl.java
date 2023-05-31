package com.zeroone.star.common.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.TPimlanguageability;
import com.zeroone.star.common.mapper.TPimlanguageabilityMapper;
import com.zeroone.star.common.service.ITPimlanguageabilityService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 语言能力 服务实现类
 * </p>
 *
 * @author loop
 * @since 2023-05-29
 */
@Service
public class TPimlanguageabilityServiceImpl extends ServiceImpl<TPimlanguageabilityMapper, TPimlanguageability> implements ITPimlanguageabilityService {

    @Autowired
    TPimlanguageabilityMapper mapper;

    @Override
    public List<String> queryLanguageLevel(String id) {
        return mapper.queryLanguageLevel(id);
    }

    @Override
    public List<String> queryLanguageType(String id) {
        return mapper.queryLanguageLevel(id);
    }

    @Override
    public List<String> queryRelationship(String id) {
        return mapper.queryRelationship(id);
    }
}
