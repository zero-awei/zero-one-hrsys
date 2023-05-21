package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.common.CommonApis;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.j3.query.common.OneConditionQuery;
import com.zeroone.star.project.j3.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.j3.common.CommonApis;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.OneConditionQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
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
@RequestMapping("common")
@Api(tags = "通用接口")
public class CommonController implements CommonApis {
    @Override
    public JsonVO<List<String>> queryOneColumn(OneConditionQuery oneConditionQuery) {
        return null;
    }


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


    @GetMapping("query-department-name")
    @ApiOperation("部门名称下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDepartmentName() {
        return null;
    }

    @Override
    public JsonVO<Map<Integer, String>> LearningFormsDropdownList() {
        return null;
    }

    @Override
    public JsonVO<Map<Integer, String>> SchoolNatureDropdownList() {
        return null;
    }

    @GetMapping("queryList")
    @ApiOperation("分页查询某人的语言能力")
    @Override
    public JsonVO<PageDTO<List<LanguageAbilityDTO>>> queryLanguageAbilityList(LanguageAbilityQuery personId) {
        return null;}
    @GetMapping("query-learning-forms")
    @ApiOperation("获取学习形式下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryLearningForms() {
        List<DropdownListOptionDTO> list = new ArrayList<>();
        //测试用例
        for (int i = 0; i < 5; i++){
            DropdownListOptionDTO dropdownListOptionDTO = new DropdownListOptionDTO();
            dropdownListOptionDTO.setKey(i);
            dropdownListOptionDTO.setValue("帅" + i);
            list.add(dropdownListOptionDTO);
        }
        return JsonVO.success(list);
    }

    @GetMapping("query-school-nature")
    @ApiOperation("获取学校性质下拉列表")
    @Override
    public JsonVO<List<DropdownListOptionDTO>> querySchoolNature() {
        List<DropdownListOptionDTO> list = new ArrayList<>();
        return JsonVO.success(list);
    }
}
