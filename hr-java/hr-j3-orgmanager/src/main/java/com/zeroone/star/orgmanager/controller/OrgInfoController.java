package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import cn.hutool.http.server.HttpServerResponse;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.orgmanager.OrgInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 描述：组织信息管接口实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/20 10:21
 */
@RestController
@RequestMapping("orginfo")
@Api(tags = "组织信息管理")
public class OrgInfoController implements OrgInfoApis {

    @PostMapping("modify-org-info")
    @ApiOperation("修改组织信息")
    @Override
    public JsonVO<Boolean> modifyOrgInfo(@RequestBody OrgInfoDTO orgInfoDTO) {
        return null;
    }

    @DeleteMapping("remove-org-info")
    @ApiOperation("删除组织信息（支持批量）")
    @Override
    public JsonVO<Boolean> removeOrgData(DeleteDTO ids) {
        return JsonVO.success(true);
    }

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

    @PutMapping("add-org-info")
    @ApiOperation("添加组织")
    @Override
    public JsonVO<Boolean> addOryData(@RequestBody OrgInfoDTO orgInfoDTO) {
        return JsonVO.success(true);
    }
}
