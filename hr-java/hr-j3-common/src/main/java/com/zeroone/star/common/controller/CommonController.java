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

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: CommonController
 * Description:
 *
 * @Author LR
 * @Create 2023/5/20 13:52
 * @Version 1.0
 */
@RestController
@RequestMapping("common")
@Api(tags = "通用接口")
public class CommonController implements CommonApis {
    @Override
    public JsonVO<List<String>> queryOneColumn(OneConditionQuery oneConditionQuery) {
        return null;
    }

    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryRewardPenaltyLevels() {
        return null;
    }

    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryTypeofMilitaryTransfer() {
        return null;
    }

    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDistributionForm() {
        return null;
    }

    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDistributionStatus() {
        return null;
    }

    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryNameofAssociation() {
        return null;
    }

    @Override
    public JsonVO<List<DropdownListOptionDTO>> queryDepartmentName() {
        return null;
    }

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
