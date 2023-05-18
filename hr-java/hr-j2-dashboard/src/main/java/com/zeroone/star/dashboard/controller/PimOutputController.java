package com.zeroone.star.dashboard.controller;


import com.zeroone.star.project.dashboard.PimOutputApi;
import com.zeroone.star.project.dto.dashboard.PimOutputDto;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/dashboard")
public class PimOutputController implements PimOutputApi {
    @ApiOperation(value = "月均产值")
    @GetMapping("/pim-output-yd")
    @Override
    public JsonVO<PimOutputDto> countByYear() {
        return null;
    }
}
