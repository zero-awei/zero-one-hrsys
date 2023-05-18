package com.zeroone.star.dashboard.service.impl;

import com.zeroone.star.dashboard.entity.BisEducation;
import com.zeroone.star.dashboard.mapper.BisEducationMapper;
import com.zeroone.star.dashboard.service.IBisEducationService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

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

    @Override
    public JsonVO<EducationQuery> getEducationDistribution() {
        return null;
    }
}
