package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.BisEducation;
import com.zeroone.star.dashboard.mapper.BisEducationMapper;
import com.zeroone.star.dashboard.service.IBisEducationService;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 学历代码表 服务实现类
 * </p>
 *
 * @author rqs
 * @since 2023-05-18
 */
@Service
@AllArgsConstructor
public class BisEducationServiceImpl extends ServiceImpl<BisEducationMapper, BisEducation> implements IBisEducationService {

    @Resource
    private BisEducationMapper bisEducationMapper;
    @Override
    public List<EducationQuery> getEducationDistribution() {
        List<EducationQuery> educationQueryList =bisEducationMapper.selectEducationQueryList();
        return educationQueryList;
    }
}
