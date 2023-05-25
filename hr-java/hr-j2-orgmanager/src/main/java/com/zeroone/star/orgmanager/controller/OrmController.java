package com.zeroone.star.orgmanager.controller;


import com.zeroone.star.orgmanager.service.IOrmService;
import com.zeroone.star.project.dto.orgmanager.OrgsectorDTO;
import com.zeroone.star.project.vo.orgmanager.DeptKqdzVO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.orgmanager.OrgmanagerApis;
import com.zeroone.star.project.query.orgmanager.KqdzQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 * 组织信息 前端控制器
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@RestController
@RequestMapping("org-manager")
@Api(tags = "组织管理")
@Validated
public class OrmController implements OrgmanagerApis {

    @Resource
    IOrmService ormorginfoService;

    @ApiOperation(value = "新增部门")
    @PostMapping("add-dept")
    @Override
    public JsonVO<String> addDept(@Valid OrgsectorDTO orgsectorDTO) {
        String result = ormorginfoService.saveDept(orgsectorDTO);
        return JsonVO.success(result) ;
    }

    @ApiOperation(value = "修改指定部门信息")
    @PostMapping("modify-dept-by-id")
    @Override
    public JsonVO<String> modifyDept(ModifyDeptInfoDTO modifyDeptInfoDTO) {
        return ormorginfoService.updateDept(modifyDeptInfoDTO);
    }

    @ApiOperation(value = "查询指定部门考勤地址列表（分页查询）")
    @GetMapping("query-bm-kqdz-by-id")
    @Override
    public JsonVO<List<DeptKqdzVO>> queryBmKqdzById(KqdzQuery kqdzQuery) {

        List<DeptKqdzVO> deptKqdz = ormorginfoService.listBmKqdz(kqdzQuery);
        return JsonVO.success(deptKqdz);
    }


}

