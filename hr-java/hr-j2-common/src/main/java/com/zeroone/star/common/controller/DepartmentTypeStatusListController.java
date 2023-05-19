package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.department_typestatuslist.DepartmentTypeStatusListDTO;
import com.zeroone.star.project.emplist.Department_typeStatusApi;
import com.zeroone.star.project.query.department_typestatuslist.DepartmentTypeStatusListQuery;
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
public class DepartmentTypeStatusListController implements Department_typeStatusApi {

    @GetMapping("departmenttype-status")
    @ApiOperation(value ="组织性质下拉列表")
    @Override
    public JsonVO<PageDTO<DepartmentTypeStatusListDTO>> queryAll(DepartmentTypeStatusListQuery query) {
        return null;
    }
}




