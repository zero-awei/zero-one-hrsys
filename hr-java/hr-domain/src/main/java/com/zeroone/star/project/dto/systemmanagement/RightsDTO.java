package com.zeroone.star.project.dto.systemmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */

@Data
@ApiModel("权限修改")
public class RightsDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private String id;
    @ApiModelProperty(value = "权限名称",example = "增加权限")
    private String rightsName;
}
