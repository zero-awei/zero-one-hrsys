package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.project.orgmanager.RemoveDeptApis;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

/**
  * @author：letian
  * @date  2023/5/19
  * @description：删除部门信息接口
  * @version: 1.0
*/
@RestController
@RequestMapping("/org-manager")
@Api(tags = "删除部门接口")
public class OrgManagerController implements RemoveDeptApis {

    @Override
    @DeleteMapping("/dept")
    @ApiOperation(value = "批量删除部门", notes = "根据多个部门ids删除部分部门")
    public JsonVO<DeptDTO> removeDepts(DeptDTO deptDTO) {
        return null;
    }

    @Override
    @ApiOperation(value = "删除部门", notes = "根据部门编号id删除指定部门")
    @DeleteMapping("/dept/{id}")
    public JsonVO<DeptDTO> removeDeptById(
            @ApiParam(value = "部门编号ID", required = true) @PathVariable("id") String id) {
        return null;
    }
}
