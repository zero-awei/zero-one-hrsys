package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.orgmanager.RemoveDeptApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
  * @author：letian
  * @date  2023/5/19
  * @description：删除部门信息接口
  * @version: 1.0
*/
@RestController
@RequestMapping("org-manager")
@Api(tags = "删除部门接口")
public class OrgManagerController implements RemoveDeptApis {
    @Resource
    private ISrforgsectorService srforgsectorService;
    @Override
    @DeleteMapping("remove-dept-by-ids")
    @ApiOperation(value = "批量删除部门", notes = "根据多个部门ids删除部分部门")
    public JsonVO<String> removeDeptByIds(DeptDTO deptDTO) {
        return srforgsectorService.removeDeptByIds(deptDTO);
    }

}
