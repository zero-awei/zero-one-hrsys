package com.zeroone.star.common.controller;

import com.zeroone.star.common.service.IDocumentTypeService;
import com.zeroone.star.common.service.IOrmpostlibService;
import com.zeroone.star.common.service.IStaffingControlService;
import com.zeroone.star.common.service.ZzmmService;
import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.dto.common.GwTypeDTO;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import com.zeroone.star.project.dto.common.StatusListDTO;
import com.zeroone.star.project.query.common.ZzmmQuery;
import com.zeroone.star.project.query.district_namestatuslist.DistrictNameStatusListQuery;
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


    @Resource
    private IStaffingControlService staffingControlService;

    @ApiOperation(value = "获取编制控制下拉列表")
    @GetMapping("query-staffing-control")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryStaffingControl() {
        return JsonVO.success(staffingControlService.listStaffingControl());
    }

    @Resource
    private IDocumentTypeService documentTypeService;

    @ApiOperation(value = "获取证件类型下拉列表")
    @GetMapping("query-document-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDocumentType() {
        return JsonVO.success(documentTypeService.listDocumentType());
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
    public JsonVO<ZzmmQuery> queryZzmm() {
        return zzmmService.getZzmm();
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

    @ApiOperation(value = "获取民族类型下拉列表")
    @GetMapping("query-ethnic-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryEthnicType() {
        return null;
    }

    @ApiOperation(value = "获取户口类型下拉列表")
    @GetMapping("query-household-registration")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryHouseholdRegistrationType() {
        return null;
    }

    @ApiOperation(value = "获取城市名称下拉列表")
    @GetMapping("query-city-name")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryCityName() {
        return null;
    }

    @ApiOperation(value = "获取区县下拉列表")
    @GetMapping("query-district-name")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDistrictName(DistrictNameStatusListQuery query) {
        return null;
    }
}
