package com.zeroone.star.project.dto.sysmanager.menumanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
@ApiModel("主页菜单数据")
public class MenuDTO {

    @ApiModelProperty(value = "菜单id",example = "自动生成")
    private String id;

    @ApiModelProperty(value = "菜单名称",example = "系统管理")
    private String name;

    @ApiModelProperty(value = "路由地址", example = "/sysmanager")
    private String path;

    @ApiModelProperty(value = "显示级别", example = "1")
    private Integer priority;

    @ApiModelProperty(value = "图标", example = "el-icon-s-tools")
    private String icon;

    @ApiModelProperty(value = "父菜单id", example = "1")
    private String parent_menu_id;

    @ApiModelProperty(value = "层次", example = "1")
    private Integer level;

    @ApiModelProperty(value = "描述", example = "系统管理")
    private String description;

    @ApiModelProperty(value = "创建人", example = "自动生成")
    private String creator;

    @ApiModelProperty(value = "创建时间", example = "自动生成")
    private Date createTime;

    @ApiModelProperty(value = "更新时间",example = "自动生成")
    private Date updateTime;

}
