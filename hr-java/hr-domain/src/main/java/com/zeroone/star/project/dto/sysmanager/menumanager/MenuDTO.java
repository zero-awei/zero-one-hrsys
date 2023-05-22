package com.zeroone.star.project.dto.sysmanager.menumanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("主页菜单数据")
public class MenuDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private String id;

    @ApiModelProperty(value = "菜单名称",example = "系统管理")
    private String name;

    @ApiModelProperty(value = "路由地址", example = "/sysmanager")
    private String path;

    @ApiModelProperty(value = "显示级别", example = "1")
    private Integer priority;

    @ApiModelProperty(value = "图标", example = "el-icon-s-tools")
    private String icon;

    @ApiModelProperty(value = "父菜单名称", example = "根菜单")
    private String parentMenuName;

    @ApiModelProperty(value = "层次", example = "1")
    private Integer level;

    @ApiModelProperty(value = "描述", example = "系统管理")
    private String description;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;

}
