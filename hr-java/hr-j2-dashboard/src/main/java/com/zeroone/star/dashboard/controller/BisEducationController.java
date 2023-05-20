package com.zeroone.star.dashboard.controller;


import com.zeroone.star.dashboard.service.IBisEducationService;
import com.zeroone.star.project.dashboard.DashboardApis;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 学历代码表 前端控制器
 * </p>
 *
 * @author rqs
 * @since 2023-05-18
 */
@RestController
@RequestMapping("dashboard")
@Api(tags = "dashboard")
public class BisEducationController implements DashboardApis {

    @Resource
    IBisEducationService bisEducationService;

    @ApiOperation(value = "学历分布")
    @GetMapping("query-education-distribution")
    @Override
    public JsonVO<EducationQuery> queryEducationDistribution() {
        return bisEducationService.getEducationDistribution();
    }
}

