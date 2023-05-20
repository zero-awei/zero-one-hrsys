package com.zeroone.star.project.query.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.List;

@EqualsAndHashCode(callSuper = false)
@Data
@ApiModel("角色菜单查询对象")
public class RoleMenuQuery {
    @ApiModelProperty(value = "角色菜单", example = "[1,2,3]")
    private List<Integer> permissionIds;
}
