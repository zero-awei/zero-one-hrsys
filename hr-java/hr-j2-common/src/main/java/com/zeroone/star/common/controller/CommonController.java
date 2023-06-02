package com.zeroone.star.common.controller;

import com.zeroone.star.common.service.*;
import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.dto.common.StatusListDTO;
import com.zeroone.star.project.dto.common.ZzmmDTO;
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

    @Resource
    IPimpersonService iPimpersonService;

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
    public JsonVO<List<StatusListDTO>> queryEmployeeStatus() {
        return JsonVO.success(iPimpersonService.listEmployeeStatus());
    }

    @Resource
    private DtService dtService;

    @ApiOperation(value = "部门类型下拉列表")
    @GetMapping("query-dtstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDTStatus() {
        return JsonVO.success(dtService.listDt());
    }

    @Resource
    private OpService opService;

    @ApiOperation(value = "组织性质下拉列表")
    @GetMapping("query-opstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryOPStatus() {
        return JsonVO.success(opService.listOp());
    }

    @Resource
    private OrService orService;

    @ApiOperation(value = "所属区域下拉列表")
    @GetMapping("query-orstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryORStatus() {
        return JsonVO.success(orService.listOr());
    }

    @Resource
    private SsService ssService;

    @ApiOperation(value = "补贴标准下拉列表")
    @GetMapping("query-ssstatus")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> querySSStatus() {
        return JsonVO.success(ssService.listSs());
    }


    @ApiOperation(value = "政治面貌下拉列表")
    @GetMapping("query-zzmm")
    @Override
    public JsonVO<List<ZzmmDTO>> queryZzmm() {
        List<ZzmmDTO> zzmmDTOList = zzmmService.getZzmm();
        return JsonVO.success(zzmmDTOList);
    }

    @Resource
    private IBloodTypeService bloodTypeService;

    @ApiOperation(value = "血型下拉列表")
    @GetMapping("query-blood-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryBloodType() {
        return JsonVO.success(bloodTypeService.listBloodType());
    }

    @Resource
    private IZoPostTypeService zoPostTypeService;

    @ApiOperation(value = "岗位分类下拉列表")
    @GetMapping("/query-post-type")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryPostType() {
        List<DropdownListOptionDTO> list = zoPostTypeService.listPostType();
        return JsonVO.success(list);
    }

    @Resource
    private IZoPostNatureService zoPostNatureService;

    @ApiOperation(value = "岗位性质下拉列表")
    @GetMapping("/query-post-nature")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryPostNature() {
        List<DropdownListOptionDTO> list = zoPostNatureService.listPostNature();
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

    @Resource
    private IZoWorkStatusService workStatusService;

    @Resource
    private IZoMaritalStatusService maritalStatusService;

    @GetMapping("query-marital-status")
    @ApiOperation(value = "婚姻状况下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryMaritalStatus() {
        List<DropdownListOptionDTO> dtoList = maritalStatusService.listMaritalStatus();
        return JsonVO.success(dtoList);
    }

    @GetMapping("query-work-status")
    @ApiOperation(value = "工作状态下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryWorkStatus() {
        List<DropdownListOptionDTO> dtoList = workStatusService.listWorkStatus();
        return JsonVO.success(dtoList);
    }


}
