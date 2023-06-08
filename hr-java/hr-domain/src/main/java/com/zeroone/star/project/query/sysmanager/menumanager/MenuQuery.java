package com.zeroone.star.project.query.sysmanager.menumanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：菜单查询数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author camille
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("菜单查询")
public class MenuQuery extends PageQuery {

    @ApiModelProperty(value = "菜单名称",example = "系统管理")
    private String name;

    @ApiModelProperty(value = "路由地址", example = "/sysmanager")
    private String path;

    @ApiModelProperty(value = "显示级别", example = "1")
    private Integer priority;

    @ApiModelProperty(value = "图标", example = "主菜单")
    private String  icon;

    @ApiModelProperty(value = "描述", example = "这是描述")
    private String description;

    @ApiModelProperty(value = "父级菜单id", example = "1")
    private Integer parent_menu_id;

    @ApiModelProperty(value = "层次", example = "1")
    private Integer level;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;
}
