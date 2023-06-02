package com.zeroone.star.dashboard.controller;


import com.zeroone.star.dashboard.service.*;
import com.zeroone.star.project.dashboard.DashboardApis;
import com.zeroone.star.project.dashboard.OrgDistributeApis;
import com.zeroone.star.project.dashboard.OrgPersonCountApis;
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
public class DashboardController implements DashboardApis, OrgDistributeApis, OrgPersonCountApis {

    @Resource
    IBisProfessoranalysisService iBisProfessoranalysisService;

    @Resource
    IBisPimoutputTService iBisPimoutputTService;

    @GetMapping("pim-title-zcdj")
    @ApiOperation(value = "职称等级分布")
    @Override
    public JsonVO<List<PimTitleDTO>> queryProfessionalRank() {
        return JsonVO.success(iBisProfessoranalysisService.listRank());
    }

    @ApiOperation(value = "月均产值")
    @GetMapping("pim-output-yd")
    @Override
    public JsonVO<List<PimOutputDTO>> queryByMonth() {
        return JsonVO.success(iBisPimoutputTService.listMonthOutput());
    }

    @ApiOperation(value = "获取机关和项目人员")
    @GetMapping("query-agency-project-staff")
    @Override
    public JsonVO<List<AgencyProjectStaffDTO>> queryAgencyProjectStaff() {
        return JsonVO.success(srforgService.listAgencyProjectStaff());
    }

    @Resource
    IBisEducationService bisEducationService;

    @ApiOperation(value = "学历分布")
    @GetMapping("query-education-distribution")
    @Override
    public JsonVO<List<EducationQuery>> queryEducationDistribution() {
        List<EducationQuery> educationDistribution = bisEducationService.getEducationDistribution();
        return JsonVO.success(educationDistribution);
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

    @Resource
    private ITPimpersonService pimpersonService;

    /**
     * 描述：年龄分布
     * 创建者：C.C.
     */
    @ApiOperation(value = "年龄分布")
    @GetMapping("/query-age-distribution")
    public JsonVO<List<AgeDTO>> queryAgeDistribution() {
        return JsonVO.success(pimpersonService.listAgeDistribution());
    }


    @Resource
    private ISrforgService srforgService;

    @ApiOperation(value = "组织分布")
    @GetMapping("/query-org-distribute")
    @Override
    public JsonVO<List<OrgDistributeDTO>> queryOrgDistribute() {
        List<OrgDistributeDTO> list = srforgService.listOrgDistribute();
        return JsonVO.success(list);
    }

    @ApiOperation(value = "组织人数")
    @GetMapping("query-org-person-count")
    @Override
    public JsonVO<List<OrgPersonCountDTO>> queryOrgPersonCount() {
        List<OrgPersonCountDTO> list = pimpersonService.listOrgPersonCount();
        return JsonVO.success(list);
    }
}
