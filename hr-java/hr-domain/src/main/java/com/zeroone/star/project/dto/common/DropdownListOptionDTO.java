package com.zeroone.star.project.dto.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：下拉列表选项传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@ApiModel("下拉列表选项传输对象")
@Data
public class DropdownListOptionDTO {
    @ApiModelProperty(value = "列表项编号", example = "10")
    private String key;
    @ApiModelProperty(value = "列表项值", example = "身份证")
    private String value;
}
