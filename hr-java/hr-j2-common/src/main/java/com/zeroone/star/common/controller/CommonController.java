package com.zeroone.star.common.controller;

import com.zeroone.star.common.service.IOrmpostlibService;
import com.zeroone.star.common.service.ZzmmService;
import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.*;
import com.zeroone.star.project.query.common.ZzmmQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：公用接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@RestController
@RequestMapping("common")
@Api(tags = "公用接口")
public class CommonController implements CommonApis {

    @Resource
    ZzmmService zzmmService;

    @ApiOperation(value = "获取编制控制下拉列表")
    @GetMapping("query-staffing-control")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryStaffingControl() {
        return null;
    }

    @ApiOperation(value = "获取证件类型下拉列表")
    @GetMapping("query-certificate-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryCertificateType() {
        return null;
    }

    @ApiOperation(value = "员工状态下拉列表")
    @GetMapping("employee-status-list")
    @Override
    public JsonVO<PageDTO<StatusListDTO>> queryEmployeeStatus() {
        return null;
    }

    @ApiOperation(value = "部门类型下拉列表")
    @GetMapping("query-dtstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDTStatus() {
        return null;
    }

    @ApiOperation(value = "组织性质下拉列表")
    @GetMapping("query-opstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryOPStatus() {
        return null;
    }

    @ApiOperation(value = "所属区域下拉列表")
    @GetMapping("query-orstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryORStatus() {
        return null;
    }

    @ApiOperation(value = "补贴标准下拉列表")
    @GetMapping("query-ssstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> querySSStatus() {
        return null;
    }


    @ApiOperation(value = "政治面貌下拉列表")
    @GetMapping("query-zzmm")
    @Override
    public JsonVO<List<ZzmmDTO>> queryZzmm() {
        List<ZzmmDTO> zzmmDTOList = zzmmService.getZzmm();
        return JsonVO.success(zzmmDTOList);
    }

    @ApiOperation(value = "血型下拉列表")
    @GetMapping("query-blood-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryBloodType() {
        return null;
    }

    @Resource
    private IOrmpostlibService ormpostlibService;

    @ApiOperation(value = "获取岗位分类下拉列表")
    @GetMapping("/query-post-classification")
    @Override
    public JsonVO<List<GwTypeDTO>> queryGwfl() {
        List<GwTypeDTO> list = ormpostlibService.getGwType();
        return JsonVO.success(list);
    }

    @ApiOperation(value = "获取岗位性质下拉列表")
    @GetMapping("/query-post-nature")
    @Override
    public JsonVO<List<PostNatureDTO>> queryPostNature() {
        List<PostNatureDTO> list = ormpostlibService.getPostNature();
        return JsonVO.success(list);
    }
}
