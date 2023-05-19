package com.zeroone.star.orgmanager.controller;


import com.zeroone.star.orgmanager.service.IOrmorginfoService;
import com.zeroone.star.project.dto.orgmanager.DeptInfoDTO;
import com.zeroone.star.project.orgmanager.OrgmanagerApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 组织信息 前端控制器
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@RestController
@RequestMapping("orgmanager")
@Api(tags = "orgmanager")
public class OrmorginfoController implements OrgmanagerApis {

    @Resource
    IOrmorginfoService ormorginfoService;

    @ApiOperation(value = "新增部门")
    @PostMapping("addDept")
    @Override
    public JsonVO<String> addDept(DeptInfoDTO deptInfoDTO) {
        return ormorginfoService.saveDept(deptInfoDTO);
    }
}

