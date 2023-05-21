package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("职务信息传输数据对象")
public class JobTitleDTO {

    @ApiModelProperty(value = "工作职务编码",example = "101")
    private String jobId; // 工作职务编码
    @ApiModelProperty(value = "职务名称",example = "董事长")
    private String title; // 职务名称
    @ApiModelProperty(value = "职务序号",example = "3")
    private int order; // 职务序号
    @ApiModelProperty(value = "职务标识",example = "039bb636-099a-4deb-bf9b-c9b865e35e0f")
    private String dutyId; //职务标识
}
