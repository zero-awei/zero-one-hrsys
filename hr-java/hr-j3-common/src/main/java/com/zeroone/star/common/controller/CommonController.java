package com.zeroone.star.common.controller;

import com.zeroone.star.common.service.ITPimlanguageabilityService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.common.CommonApis;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.j3.query.common.*;
import com.zeroone.star.project.j3.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

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
@RequestMapping("common")
@Api(tags = "通用接口")
public class CommonController implements CommonApis {
    @Autowired
    ITPimlanguageabilityService languageabilityService;

    @GetMapping("query-start-position-title")
    @ApiOperation("职务名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryPositionTitle(PositionTitleDropdownListQuery query) {
        return null;
    }

    @GetMapping("query-start-job-title")
    @ApiOperation("岗位名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryJobTitle(JobTitleDropdownListQuery query) {
        return null;
    }

    @GetMapping("query-reward-levels")
    @ApiOperation("奖惩级别下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryRewardPenaltyLevels() {
        return null;
    }


    @ApiOperation("军转类型下拉菜单")
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

    @GetMapping("query-sector-name")
    @ApiOperation("部门名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> querySectorName(SectorNameQuery sectorNameQuery) {
        return null;
    }

//    @GetMapping("query-languageAbility-list")
//    @ApiOperation("分页查询某人的语言能力")
//    @Override
//    public JsonVO<PageDTO<List<LanguageAbilityDTO>>> queryLanguageAbilityList(LanguageAbilityQuery personId) {
//        return null;
//    }

    @GetMapping("query-learning-forms")
    @ApiOperation("学习形式下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryLearningForms() {
        return null;
    }

    @GetMapping("query-school-nature")
    @ApiOperation("学校性质下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> querySchoolNature() {
        return null;
    }

    @GetMapping("query-common-discipline")
    @ApiOperation("获取学科下拉列表")
    @Override
    public JsonVO<List<String>> listDisciplineType(DisciplineTypeQuery discipline) {
        return null;
    }

    @GetMapping("query-common-education")
    @ApiOperation("获取学历下拉列表")
    @Override
    public JsonVO<List<String>> listEducationType(EducationTypeQuery education) {
        return null;
    }


    @GetMapping("query-relationship")
    @ApiOperation("与本人关系列表")
    @Override
    public JsonVO<List<String>> queryRelationship() {
        String id = "4E74D429-DE85-41BB-B900-6009A23895D6";
        return JsonVO.success(languageabilityService.queryRelationship(id));
    }

    @GetMapping("query-entry-channel")
    @ApiOperation("入职渠道下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryEntryChannel() {
        return null;
    }

    @GetMapping("query-allocation")
    @ApiOperation(("分配方式下拉列表"))
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryAllocation() {
        return null;
    }
    @GetMapping("query-language-type")
    @ApiOperation("语种类型下拉列表")
    public JsonVO<List<String>> queryLanguageType() {
        String id = "4AD0B58B-E3E7-44B2-8F67-302C8F95C7E9"; //语种类型id
        return JsonVO.success(languageabilityService.queryLanguageType(id));
    }

    @GetMapping("query-language-level")
    @ApiOperation("外语等级下拉列表")
    public JsonVO<List<String>> queryLanguageLevel(){
        String id = "F1990A43-1ED9-4001-BA4A-1F3B221653A4";
        return  JsonVO.success(languageabilityService.queryLanguageLevel(id));//外语等级id
    }
}
