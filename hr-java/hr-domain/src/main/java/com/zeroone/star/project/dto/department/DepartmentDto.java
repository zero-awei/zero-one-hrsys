package com.zeroone.star.project.dto.department;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("部门查询")
public class DepartmentDto {
    @ApiModelProperty(value = "唯一编号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "部门名称", example = "市场营销部")
    private String name;
}
