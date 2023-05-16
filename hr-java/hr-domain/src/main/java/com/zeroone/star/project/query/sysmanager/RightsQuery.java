package com.zeroone.star.project.query.sysmanager;

import com.zeroone.star.project.query.PageQuery;
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

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("权限分页查询")
public class RightsQuery extends PageQuery {
    @ApiModelProperty(value = "权限名称",example = "增加权限")
    private String rightsName;
    @ApiModelProperty(value = "权限url", example = "/login")
    private String rightsUrl;
    @ApiModelProperty(value = "父权限名称", example = "根权限")
    private String parentRightsName;
    @ApiModelProperty(value = "父权限url", example = "/root")
    private String parentRightsUrl;
}
