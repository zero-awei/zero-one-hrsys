package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.BisEducation;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

/**
 * <p>
 * 学历代码表 服务类
 * </p>
 *
 * @author rqs
 * @since 2023-05-18
 */
public interface IBisEducationService extends IService<BisEducation> {
    @GetMapping("/get-education-distribution")
    List<EducationQuery> getEducationDistribution();
}
