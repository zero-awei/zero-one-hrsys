package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.project.sysmanager.RolesApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.service.IRoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.management.relation.Role;

/**
 * <p>
 * 角色表 前端控制器
 * </p>
 *
 * @author alan
 * @since 2023-05-20
 */

@Slf4j
@RestController
@Api(tags="角色管理")
@RequestMapping("/roles")
public class RoleController implements RolesApis {

    @Resource
    IRoleService service;

    @ApiOperation(value = "查询一个角色")
    @GetMapping("query-one")
    @Override
    public JsonVO<RoleDTO> queryById(Integer id) {
        return null;
    }
    @ApiOperation(value = "删除角色")
    @DeleteMapping("delete")
    @Override
    public JsonVO<ResultStatus> deleteByName(RoleDTO dto) {
        return null;
    }
    @ApiOperation(value = "增加角色")
    @PostMapping("add-one")
    @Override
    public JsonVO<ResultStatus> addOneRole(RoleDTO dto) {
        return null;
    }
    @ApiOperation(value = "修改角色")
    @PutMapping("modify")
    @Override
    public JsonVO<ResultStatus> modifyRole(RoleDTO dto) {
        return null;
    }
}

