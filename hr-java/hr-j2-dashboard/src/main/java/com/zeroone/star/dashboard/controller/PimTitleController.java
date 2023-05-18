package com.zeroone.star.dashboard.controller;


import com.zeroone.star.project.dashboard.PimTitleApi;
import com.zeroone.star.project.dto.dashboard.PimTitleDto;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/dashboard")
public class PimTitleController implements PimTitleApi {

    @GetMapping("/pim-title-zcdj")
    @ApiOperation(value = "职称等级")
    @Override
    public JsonVO<PimTitleDto> count() {
        return null;
    }

}
