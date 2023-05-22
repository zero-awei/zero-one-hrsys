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

    @NotBlank(message="id不能为空")
    @ApiModelProperty(value = "菜单编号", example = "1")
    private int id;

    @ApiModelProperty(value = "菜单名", example = "主页")
    private String text;

    @ApiModelProperty(value = "链接地址", example = "https://xxxxxx")
    private String link_url;

    @ApiModelProperty(value = "路由地址", example = "/dashboard")
    private String path;

    @ApiModelProperty(value = "显示优先级别", example = "1")
    private int priority;

    @ApiModelProperty(value = "图标", example = "图标")
    private String icon;

    @ApiModelProperty(value = "描述", example = "菜单")
    private String description;

    @ApiModelProperty(value = "父级菜单编号", example = "1")
    private int parent_menu_id;

    @ApiModelProperty(value = "层次级别", example = "1")
    private int level;

    @ApiModelProperty(value = "是否启用，0为禁用，1为启用", example = "1")
    private boolean is_enable;
}
