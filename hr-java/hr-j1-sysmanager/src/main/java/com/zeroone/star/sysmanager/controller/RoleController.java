package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.project.sysmanager.RolesApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.IRoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

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
@RestController
@Api(tags="角色管理")
@RequestMapping("/roles")
public class RoleController implements RolesApis {

    @Resource
    IRoleService service;

    @GetMapping("get-by-id")
    @ApiOperation(value = "编号查询")
    @Override
    public JsonVO<RoleDTO> queryById(Integer id) {
        return JsonVO.success(service.getById(id));
    }

    @Override
    public JsonVO<Void> deleteByName(String name) {
        return null;
    }

    @Override
    public JsonVO<RoleDTO> insertOneRole(Integer id, String name, String keyword, String description) {
        return null;
    }

    @Override
    public JsonVO<RoleDTO> modifyOneRole(Role role) {
        return null;
    }



}

