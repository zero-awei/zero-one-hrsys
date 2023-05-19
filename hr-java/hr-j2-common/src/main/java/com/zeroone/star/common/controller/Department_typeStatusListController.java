package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.department_typestatuslist.Department_typeStatusListDTO;
import com.zeroone.star.project.emplist.Department_typeStatusApi;
import com.zeroone.star.project.query.department_typestatuslist.Department_typeStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author abner
 * @version 1.0
 */

@RestController
@RequestMapping("employee")
public class Department_typeStatusListController implements Department_typeStatusApi {

    @RequestMapping("Department_type-status")
    @ApiOperation(value ="组织性质下拉列表")
    @Override
    public JsonVO<PageDTO<Department_typeStatusListDTO>> queryAll(Department_typeStatusListQuery query) {
        return null;
    }
}
