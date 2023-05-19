package com.zeroone.star.project.dto.dashboard;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("职称分布查询")
public class PimTitleDTO {
    @ApiModelProperty(value = "职称等级",example = "10")
    private String zcdj;
    @ApiModelProperty(value = "人数",example = "3")
    private int count;
}
