package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.organizational_propertystatuslist.OrganizationalPropertyStatusListDTO;
import com.zeroone.star.project.emplist.Organizational_propertyStatusApi;
import com.zeroone.star.project.query.organizational_propertystatuslist.OrganizationalPropertyStatusListQuery;
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
public class OrganizationalPropertyStatusListController implements Organizational_propertyStatusApi {

    @GetMapping("organizationalproperty-status")
    @ApiOperation(value = "组织性质下拉列表")

    @Override
    public JsonVO<PageDTO<OrganizationalPropertyStatusListDTO>> queryAll(OrganizationalPropertyStatusListQuery query) {
        return null;
    }
}
