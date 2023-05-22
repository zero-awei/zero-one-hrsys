package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

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
    @ApiModelProperty(value = "组织id列表", example = "[\"aaa\",\"bbb\"]")
    private List<String> ids;

}
