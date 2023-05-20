package com.zeroone.star.dashboard.controller;


import com.zeroone.star.dashboard.service.IBisEducationService;
import com.zeroone.star.project.dashboard.DashboardApis;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import com.zeroone.star.project.dto.dashboard.PimTitleDTO;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("dashboard")
@Api(tags = "dashboard")
public class DashboardController implements DashboardApis {

    @GetMapping("pim-title-zcdj")
    @ApiOperation(value = "职称等级分布")
    @Override
    public JsonVO<PimTitleDTO> queryProfessionalRank() {
        return null;
    }

    @ApiOperation(value = "月均产值")
    @GetMapping("pim-output-yd")
    @Override
    public JsonVO<PimOutputDTO> queryByMonth() {
        return null;
    }

    @ApiOperation(value = "获取机关和项目人员")
    @GetMapping("query-agency-project-staff")
    @Override
    public JsonVO<List<AgencyProjectStaffDTO>> queryAgencyProjectStaff() {
        return null;
    }

    @Resource
    IBisEducationService bisEducationService;

    @ApiOperation(value = "学历分布")
    @GetMapping("query-education-distribution")
    @Override
    public JsonVO<EducationQuery> queryEducationDistribution() {
        return bisEducationService.getEducationDistribution();
    }
}
