package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.subsidy_standardstatuslist.Subsidy_standardStatusListDTO;
import com.zeroone.star.project.emplist.Subsidy_standardStatusApi;
import com.zeroone.star.project.query.subsidy_standardstatuslist.Subsidy_standardStatusListQuery;
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
public class Subsidy_standardStatusListController implements Subsidy_standardStatusApi {

    @GetMapping("subsidy-standard-status")
    @ApiOperation(value = "补贴标准下拉列表")
    @Override
    public JsonVO<PageDTO<Subsidy_standardStatusListDTO>> queryAll(Subsidy_standardStatusListQuery query) {
        return null;
    }
}
