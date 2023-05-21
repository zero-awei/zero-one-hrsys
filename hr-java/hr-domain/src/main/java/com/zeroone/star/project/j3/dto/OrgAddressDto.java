package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：组织地址传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */

@Data
@ApiModel("组织地址传输对象")
public class OrgAddressDto {
    @ApiModelProperty(value = "组织ID", example = "1")
    private Long orgId;
}