package com.zeroone.star.project.dto.sysmanager.userrolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("用户角色数据传输对象")
public class UserRoleDTO {

    @ApiModelProperty(value = "用户id", example = "1")
    private String userId;

    @ApiModelProperty(value = "角色id", example = "1")
    private String roleId;
}
