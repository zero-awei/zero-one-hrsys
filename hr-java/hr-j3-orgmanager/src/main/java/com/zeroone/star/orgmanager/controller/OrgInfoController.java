package com.zeroone.star.orgmanager.controller;

import cn.hutool.http.server.HttpServerResponse;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.orgmanager.OrgInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：组织信息管理接口实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */
@RestController
@RequestMapping("orginfo")
@Api(tags = "组织信息管理")
public class OrgInfoController implements OrgInfoApis {

    @DeleteMapping("delete-org-address")
    @ApiOperation("删除指定组织地址信息（支持批量）")
    @Override
    public JsonVO<Boolean> deleteOrgAddress(@RequestBody OrgAddressDto ids) {
        return null;
    }

    @DeleteMapping("export-org-address")
    @ApiOperation("导出指定组织地址信息")
    @Override
    public JsonVO<Boolean> exportOrgAddress(HttpServerResponse response,OrgAddressDto orgAddressDto) {
        return null;
    }
}
