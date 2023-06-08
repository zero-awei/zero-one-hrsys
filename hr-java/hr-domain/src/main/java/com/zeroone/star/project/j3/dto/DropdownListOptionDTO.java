package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/19 20:21
 */
@ApiModel("下拉列表选项传输对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class DropdownListOptionDTO {
    @ApiModelProperty(value = "列表项编号", example = "1")
    private String key;
    @ApiModelProperty(value = "列表项值", example = "身份证")
    private String value;



}
