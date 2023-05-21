package com.zeroone.star.common.controller;

import com.zeroone.star.project.j3.common.CommonApis;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.OneConditionQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Map;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/20 15:46
 */
@RestController
@Api(tags = "公用接口common")
@RequestMapping("common")
public class CommonController implements CommonApis {

    @GetMapping("query-start-position-title")
    @ApiOperation("职务名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryPositionTitle() {
        return null;
    }

    @GetMapping("query-start-job-title")
    @ApiOperation("岗位名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryJobTitle() {
        return null;
    }

    @GetMapping("query-reward-levels")
    @ApiOperation("奖惩级别下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryRewardPenaltyLevels() {
        return null;
    }

    @GetMapping("query-type-of-military-transfer")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryTypeofMilitaryTransfer() {
        return null;
    }

    @GetMapping("query-distribution-form")
    @ApiOperation("分配形式下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDistributionForm() {
        return null;
    }

    @GetMapping("query-distribution-status")
    @ApiOperation("分配状态下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDistributionStatus() {
        return null;
    }

    @GetMapping("query-name-of-association")
    @ApiOperation("组织名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryNameofAssociation() {
        return null;
    }

    @GetMapping("query-department-name")
    @ApiOperation("部门名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDepartmentName() {
        return null;
    }
}
