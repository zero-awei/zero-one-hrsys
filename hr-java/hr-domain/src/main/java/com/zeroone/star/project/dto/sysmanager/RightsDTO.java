package com.zeroone.star.project.dto.sysmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author
 * @version 1.0.0
 */

@Data
@ApiModel("权限修改")
public class RightsDTO {
    /**
     * 唯一编号
     */
    @ApiModelProperty(value = "唯一编号",example = "1")
    private String id;
    
    /**
     * 权限名称
     */
    @ApiModelProperty(value = "权限名称",example = "增加权限")
    private String rightsName;
}
