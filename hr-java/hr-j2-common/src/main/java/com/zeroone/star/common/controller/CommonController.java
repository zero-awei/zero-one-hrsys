package com.zeroone.star.common.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.StatusListDto;
import com.zeroone.star.project.emplist.CommonApi;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("common")
public class CommonController implements CommonApi {
    @ApiOperation(value = "员工状态下拉列表")
    @GetMapping("employee-status-list")
    @Override
    public JsonVO<PageDTO<StatusListDto>> queryEmployeeStatus() {
        return null;
    }
}
