package com.zeroone.star.common.controller.languageability;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.common.languageability.LanguageAbilityApis;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.j3.query.common.OneConditionQuery;
import com.zeroone.star.project.j3.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@Api(tags = "公用接口languageability")
@RequestMapping("languageability")
public class LanguageAbilityController implements LanguageAbilityApis {


    @GetMapping("querylist")
    @ApiOperation("分页查询某人的语言能力")
    @Override
    public JsonVO<PageDTO<List<LanguageAbilityDTO>>> queryLanguageAbilityList(LanguageAbilityQuery personId) {
        return null;
    }
}
