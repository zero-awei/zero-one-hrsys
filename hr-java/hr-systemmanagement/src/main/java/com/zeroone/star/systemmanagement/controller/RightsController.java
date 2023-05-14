package com.zeroone.star.systemmanagement.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.systemmanagement.RightsDTO;
import com.zeroone.star.project.query.systmmanagement.RightsQuery;
import com.zeroone.star.project.systemmanagement.RightsApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */

@RestController
@RequestMapping("/rights")
public class RightsController implements RightsApis {
    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<RightsDTO>> queryAll(RightsQuery query) {
        return null;
    }

}
