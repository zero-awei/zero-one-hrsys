package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.owning_regionstatuslist.OwningRegionStatusListDTO;
import com.zeroone.star.project.emplist.Owning_regionStatusApi;
import com.zeroone.star.project.query.owning_regionstatuslist.OwningRegionStatusListQuery;
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
public class OwningRegionStatusListController implements Owning_regionStatusApi {
    @GetMapping("owningregion-status")
    @ApiOperation(value = "所属区域下拉列表")

    @Override
    public JsonVO<PageDTO<OwningRegionStatusListDTO>> queryAll(OwningRegionStatusListQuery query) {
        return null;
    }
}
