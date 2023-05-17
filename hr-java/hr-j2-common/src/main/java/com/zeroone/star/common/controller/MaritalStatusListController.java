package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.maritalstatuslist.MaritalStatusListDTO;
import com.zeroone.star.project.emplist.MaritalStatusApi;
import com.zeroone.star.project.query.maritalstatuslist.MaritalStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("employee")
public class MaritalStatusListController implements MaritalStatusApi {

    @RequestMapping("marital-status")
    @ApiOperation(value = "婚姻状况列表")
    @Override
    public JsonVO<PageDTO<MaritalStatusListDTO>> queryAll(MaritalStatusListQuery query) {
        return null;
    }
}
