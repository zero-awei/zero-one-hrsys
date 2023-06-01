package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("月均产值")
public class PimOutputDTO {
    @ApiModelProperty(value = "月均产值", example = "100000")
    private Integer output;
    @ApiModelProperty(value = "月份", example = "1")
    private String  monthly;
}
