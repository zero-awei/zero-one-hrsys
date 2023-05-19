package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("查询产值")
public class PimOutputDto {
    @ApiModelProperty(value = "月均产值", example = "100000")
    private Integer yd;
}
