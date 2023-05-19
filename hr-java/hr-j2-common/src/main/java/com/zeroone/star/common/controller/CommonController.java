package com.zeroone.star.common.controller;

import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.dto.common.StatusListDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：公用接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@RestController
@RequestMapping("common")
@Api(tags = "common")
public class CommonController implements CommonApis {
    @ApiOperation(value = "获取编制控制下拉列表")
    @GetMapping("query-staffing-control")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryStaffingControl() {
        return null;
    }

    @ApiOperation(value = "获取证件类型下拉列表")
    @GetMapping("query-certificate-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryCertificateType() {
        return null;
    }

    @ApiOperation(value = "员工状态下拉列表")
    @GetMapping("employee-status-list")
    @Override
    public JsonVO<PageDTO<StatusListDTO>> queryEmployeeStatus() {
        return null;
    }
}
