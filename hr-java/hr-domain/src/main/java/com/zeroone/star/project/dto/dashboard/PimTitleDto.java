package com.zeroone.star.project.dto.dashboard;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("职称分布查询")
public class PimTitleDto {
    @ApiModelProperty(value = "职称等级",example = "10")
    private String zcdj;
}
