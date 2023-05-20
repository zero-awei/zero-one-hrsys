package com.zeroone.star.project.query.sysmanager.menumanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;


@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("菜单查询")
public class MenuQuery extends PageQuery {

    @ApiModelProperty(value = "唯一编号",example = "1")
    private String id;

    @ApiModelProperty(value = "菜单名称",example = "系统管理")
    private String name;

    @ApiModelProperty(value = "路由地址", example = "/sysmanager")
    private String path;

    @ApiModelProperty(value = "显示级别", example = "1")
    private Integer priority;

    @ApiModelProperty(value = "父菜单名称", example = "根菜单")
    private String parentMenuName;

    @ApiModelProperty(value = "层次", example = "1")
    private Integer level;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;
}
