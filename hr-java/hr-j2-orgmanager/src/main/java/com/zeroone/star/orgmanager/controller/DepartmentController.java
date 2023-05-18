package com.zeroone.star.orgmanager.controller;


import com.zeroone.star.project.department.DepartmentApi;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.department.DepartmentDto;
import com.zeroone.star.project.query.department.DepartmentQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/orgmanager")
public class DepartmentController implements DepartmentApi {

    @GetMapping("/org-list")
    @ApiOperation(value = "分页查询部门信息")
    @Override
    public JsonVO<PageDTO<DepartmentDto>> queryAllDepartment(DepartmentQuery query) {
        return null;
    }


}
