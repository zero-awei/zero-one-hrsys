package com.zeroone.star.project.query.dashboard;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@ApiModel("测试查询对象")
public class PimOutputQuery {

    @ApiModelProperty(value = "年份", example = "2023")
    private Integer nd;
}
