package com.zeroone.star.dashboard.service;

import com.zeroone.star.dashboard.entity.BisEducation;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

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
    JsonVO<EducationQuery> getEducationDistribution();
}
