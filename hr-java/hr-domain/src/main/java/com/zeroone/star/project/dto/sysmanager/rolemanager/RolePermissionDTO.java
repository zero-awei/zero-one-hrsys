package com.zeroone.star.project.dto.sysmanager.rolemanager;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class RolePermissionDTO {
        /**
        * 角色Id
        */
        @ApiModelProperty(value = "角色Id",example = "1")
        private int roleId;
        /**
        * 权限Id列表
        */
        @ApiModelProperty(value = "权限Id列表",example = "[1,2,3]")
        private List<Integer> permissionIds;
}
