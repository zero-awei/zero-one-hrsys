package com.zeroone.star.dashboard.controller;

import com.zeroone.star.project.dashboard.PimVocationalListApi;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.dashboard.PimVocationalListDTO;
import com.zeroone.star.project.query.dashboard.PimVocationalListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 12:05
 */
@RestController
@RequestMapping("dashboard")
@Api(tags = "dashboard")
public class PimVocationalController implements PimVocationalListApi {


    @GetMapping("fetchrep-vocational")
    @ApiOperation(value = "职业资格列表")
    @Override
    public JsonVO<List<PimVocationalListDTO>> queryPimVocational(PimVocationalListQuery query) {
        return null;
    }
}
