package com.zeroone.star.project.dto.common;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 员工状态列表
 */
@Data
@ApiModel("员工状态列表")
public class StatusListDTO {
    @ApiModelProperty(value = "唯一编号", example = "1")
    private String id;
    @ApiModelProperty(value = "状态", example = "见习")
    private String status;

}
