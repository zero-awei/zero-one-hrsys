package com.zeroone.star.project.query.rolescontrol;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.List;

@EqualsAndHashCode(callSuper = false)
@Data
@ApiModel("角色权限查询对象")
public class RolePermissionQuery {
    @ApiModelProperty(value = "角色权限", example = "[1,2,3]")
    private List<Integer> permissionIds;
}
