package com.zeroone.star.orgmanager.controller;

<<<<<<< HEAD
import com.zeroone.star.project.dto.orgmanager.ExportDTO;
import com.zeroone.star.project.orgmanager.DepartmentApis;
import com.zeroone.star.project.query.orgmanager.ExportAttendanceAddressQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
=======

import com.zeroone.star.project.department.DepartmentApi;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.DepartmentDto;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import com.zeroone.star.project.vo.JsonVO;
>>>>>>> origin/j2-employee_status_list-WxS1729
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

<<<<<<< HEAD
/**
 * <p>
 * 描述：部门信息接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@RestController
@RequestMapping("org")
@Api(tags = "departments")
public class DepartmentController implements DepartmentApis {
    @ApiOperation(value = "导出部门信息")
    @GetMapping("export-departments")
    @Override
    public JsonVO<ExportDTO> execExportDepartments() {
        return null;
    }

    @ApiOperation(value = "导出指定部门考勤地址信息")
    @GetMapping("export-attendance-address")
    @Override
    public JsonVO<ExportDTO> execExportAttendanceAddress(ExportAttendanceAddressQuery query) {
        return null;
    }
=======
@RestController
@RequestMapping("org-manager")
public class DepartmentController implements DepartmentApi {

    @GetMapping("org-list")
    @ApiOperation(value = "分页查询部门信息")
    @Override
    public JsonVO<PageDTO<DepartmentDto>> queryAllDepartment(DepartmentQuery query) {
        return null;
    }


>>>>>>> origin/j2-employee_status_list-WxS1729
}
