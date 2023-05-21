package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.zeroone.star.project.orgmanager.RemoveDeptApis;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.query.orgmanager.DeptQuery1;
import com.zeroone.star.project.query.orgmanager.DeptQuery2;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

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
    @Resource
    private ISrforgsectorService srforgsectorService;
    @Override
    @DeleteMapping("/dept")
    @ApiOperation(value = "批量删除部门", notes = "根据多个部门ids删除部分部门")
    public JsonVO<DeptDTO> removeDepts(DeptQuery2 deptQuery2) {
        if (srforgsectorService.removeDepts(deptQuery2)) {
            return JsonVO.create(null, ResultStatus.SUCCESS);
        }
        return JsonVO.create(null, ResultStatus.FAIL);
    }

    @Override
    @ApiOperation(value = "删除部门", notes = "根据部门编号id删除指定部门")
    @DeleteMapping("/dept/{id}")
    public JsonVO<DeptDTO> removeDeptById(DeptQuery1 deptQuery1) {
        if (srforgsectorService.removeDeptById(deptQuery1)) {
            return JsonVO.create(null, ResultStatus.SUCCESS);
        }
        return JsonVO.create(null, ResultStatus.FAIL);
    }
}
