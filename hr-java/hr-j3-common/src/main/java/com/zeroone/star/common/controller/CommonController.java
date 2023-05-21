package com.zeroone.star.common.controller;

import com.zeroone.star.project.j3.common.CommonApis;
import com.zeroone.star.project.j3.query.common.DisciplineTypeQuery;
import com.zeroone.star.project.j3.query.common.EducationTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：公共管理接口实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */
@RestController
@RequestMapping("common")
@Api(tags = "公共管理")
public class CommonController implements CommonApis {

    @GetMapping("remove-common-discipline")
    @ApiOperation("获取学科下拉列表")
    @Override
    public JsonVO<List<String>> listDisciplineType(DisciplineTypeQuery discipline) {
        return null;
    }

    @GetMapping("remove-common-education")
    @ApiOperation("获取学历下拉列表")
    @Override
    public JsonVO<List<String>> listEducationType(EducationTypeQuery education) {
        return null;
    }
}
