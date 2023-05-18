package com.zeroone.star.project.dto.sysmanager.menumanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("主页菜单数据")
public class MenuDTO {
    @ApiModelProperty(value = "序号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "菜单名称", example = "主页")
    private String text;
    @ApiModelProperty(value = "图标", example = "dashboard")
    private String icon;
    @ApiModelProperty(value = "路由地址", example = "/dashboard")
    private String href;
    @ApiModelProperty(value = "父级菜单编号", example = "0")
    private Integer pid;

}
