package com.zeroone.star.dashboard.controller;

import com.zeroone.star.project.dashboard.DashboardApis;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：系统首页
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@RestController
@RequestMapping("dashboard")
@Api(tags = "dashboard")
public class DashboardController implements DashboardApis {
    @ApiOperation(value = "获取机关和项目人员")
    @GetMapping("query-agency-project-staff")
    @Override
    public JsonVO<List<AgencyProjectStaffDTO>> queryAgencyProjectStaff() {
        return null;
    }
}
