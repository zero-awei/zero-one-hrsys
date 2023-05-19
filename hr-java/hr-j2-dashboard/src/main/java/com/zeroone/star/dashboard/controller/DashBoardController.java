package com.zeroone.star.dashboard.controller;


import com.zeroone.star.project.dashboard.DashBoardApi;
import com.zeroone.star.project.dto.dashboard.PimOutputDto;
import com.zeroone.star.project.dto.dashboard.PimTitleDto;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("dashboard")
@Api(tags = "dashboard")
public class DashBoardController implements DashBoardApi {

    @GetMapping("pim-title-zcdj")
    @ApiOperation(value = "职称等级分布")
    @Override
    public JsonVO<PimTitleDto> queryProfessionalRank() {
        return null;
    }

    @ApiOperation(value = "月均产值")
    @GetMapping("pim-output-yd")
    @Override
    public JsonVO<PimOutputDto> queryByMonth() {
        return null;
    }

}
