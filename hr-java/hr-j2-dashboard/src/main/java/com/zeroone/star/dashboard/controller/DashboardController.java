package com.zeroone.star.dashboard.controller;


import com.zeroone.star.dashboard.service.IBisEducationService;
import com.zeroone.star.dashboard.service.IBisEmployeeanalysisService;
import com.zeroone.star.dashboard.service.IBisRegisterTService;
import com.zeroone.star.dashboard.service.ISrforgService;
import com.zeroone.star.project.dashboard.DashboardApis;
import com.zeroone.star.project.dashboard.OrgDistributeApis;
import com.zeroone.star.project.dto.dashboard.*;
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
@Api(tags = "系统首页")
public class DashboardController implements DashboardApis, OrgDistributeApis {

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

    @Resource
    private IBisRegisterTService bisRegisterTService;

    @GetMapping("query-vocational")
    @ApiOperation(value = "职业资格")
    @Override
    public JsonVO<List<PimVocationalDTO>> queryVocational() {
        List<PimVocationalDTO> dtoList = bisRegisterTService.listVocational();
        return JsonVO.success(dtoList);
    }

    /**
     * 描述：年龄分布
     * 创建者：C.C.
     */
    @ApiOperation(value = "年龄分布")
    @GetMapping("/query-age-distribution")
    public JsonVO<List<AgeDTO>> queryAgeDistribution() {
        return null;
    }

    @Resource
    private ISrforgService srforgService;
    @Resource
    private IBisEmployeeanalysisService bisEmployeeanalysisService;

    @ApiOperation(value = "获取组织分布信息")
    @GetMapping("/query-org-distribute")
    @Override
    public JsonVO<List<OrgDistributeDTO>> queryOrgDistribute() {
        List<OrgDistributeDTO> list = srforgService.getAllOrg();
        return JsonVO.success(list);
    }

    @ApiOperation(value = "获取组织人数信息")
    @GetMapping("/query-org-count")
    @Override
    public JsonVO<List<OrgEmployeeCountDTO>> queryEmployeeCount() {
        List<OrgEmployeeCountDTO> list = bisEmployeeanalysisService.getOrgCount();
        return JsonVO.success(list);
    }
}
