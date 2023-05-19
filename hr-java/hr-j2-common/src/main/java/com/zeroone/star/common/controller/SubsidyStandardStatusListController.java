package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.subsidy_standardstatuslist.SubsidyStandardStatusListDTO;
import com.zeroone.star.project.emplist.Subsidy_standardStatusApi;
import com.zeroone.star.project.query.subsidy_standardstatuslist.SubsidyStandardStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author abner
 * @version 1.0
 */

@RestController
@RequestMapping("common")
@Api(tags = "common")
public class SubsidyStandardStatusListController implements Subsidy_standardStatusApi {

    @GetMapping("subsidystandard-status")
    @ApiOperation(value = "补贴标准下拉列表")
    @Override
    public JsonVO<PageDTO<SubsidyStandardStatusListDTO>> queryAll(SubsidyStandardStatusListQuery query) {
        return null;
    }
}
