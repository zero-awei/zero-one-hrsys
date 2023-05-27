package com.zeroone.star.project.dto.sysmanager.rolemenumanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("角色菜单数据传输对象")
public class RoleMenuDTO {
    @ApiModelProperty(value = "角色id", example = "1")
    private String roleId;

    @ApiModelProperty(value = "菜单id", example = "1")
    private String menuId;
}
