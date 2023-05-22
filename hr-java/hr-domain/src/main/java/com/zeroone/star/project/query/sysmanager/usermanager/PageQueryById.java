package com.zeroone.star.project.query.sysmanager.usermanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;


/**
 * xiao
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户分页查询")
public class PageQueryById extends PageQuery {
    @NotBlank(message = "id不能为空")
    @ApiModelProperty(value = "ID",example = "ABC123")
    private String id;
}
