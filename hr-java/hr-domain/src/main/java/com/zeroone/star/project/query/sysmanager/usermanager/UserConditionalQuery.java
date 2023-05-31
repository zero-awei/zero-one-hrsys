package com.zeroone.star.project.query.sysmanager.usermanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("模糊查询用户信息")
public class UserConditionalQuery extends PageQuery {
    @NotBlank(message = "条件不能为空")
    @ApiModelProperty(value = "condition", example = "2")
    private String condition;
}
