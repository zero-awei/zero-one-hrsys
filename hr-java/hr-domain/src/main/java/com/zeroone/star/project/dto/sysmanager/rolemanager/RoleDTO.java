package com.zeroone.star.project.dto.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("角色管理")
public class RoleDTO {

    @ApiModelProperty(value = "编号", example = "2")
    private String id;

    @ApiModelProperty(value = "角色名", example = "普通管理员")
    private String name;

    @ApiModelProperty(value = "keyword", example = "ADMIN")
    private String keyword;

    @ApiModelProperty(value = "描述", example = "这是一个管理员用户")
    private String description;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;
}