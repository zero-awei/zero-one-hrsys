package com.zeroone.star.project.dto.sysmanager.rolepowermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("角色权限数据传输对象")
public class RolePowerDTO {
    @ApiModelProperty(value = "角色id", example = "1")
    private String roleId;

    @ApiModelProperty(value = "权限id", example = "1")
    private String powerId;

}
