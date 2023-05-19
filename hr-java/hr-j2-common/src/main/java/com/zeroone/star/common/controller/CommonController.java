package com.zeroone.star.common.controller;

<<<<<<< HEAD
import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
=======

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.StatusListDto;
import com.zeroone.star.project.emplist.CommonApi;
import com.zeroone.star.project.vo.JsonVO;
>>>>>>> origin/j2-employee_status_list-WxS1729
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

<<<<<<< HEAD
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
=======
@RestController
@RequestMapping("common")
public class CommonController implements CommonApi {
    @ApiOperation(value = "员工状态下拉列表")
    @GetMapping("employee-status-list")
    @Override
    public JsonVO<PageDTO<StatusListDto>> queryEmployeeStatus() {
>>>>>>> origin/j2-employee_status_list-WxS1729
        return null;
    }
}
