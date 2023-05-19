package com.zeroone.star.project.j3.query.languageability;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("语言能力查询对象（用户标识）")
public class LanguageAbilityQuery extends PageQuery {

    @NotBlank(message = "用户标识不能为空")
    @ApiModelProperty(value = "用户标识", example = "username")
    private String personId;

}
