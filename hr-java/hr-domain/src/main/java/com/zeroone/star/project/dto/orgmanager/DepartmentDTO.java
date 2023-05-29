package com.zeroone.star.project.dto.orgmanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("部门查询")
public class DepartmentDTO{
    @ApiModelProperty(value = "排序", example = "1")
    private Integer ordervalue;
    @ApiModelProperty(value = "部门名称", example = "市场营销部")
    private String orgsectorname;
    @ApiModelProperty(value = "部门简称", example = "市场部")
    private String shortname;
    @ApiModelProperty(value = "部门编号", example = "101")
    private String orgcode;
    @ApiModelProperty(value = "所属组织", example = "光映科技")
    private String orgname;
    @ApiModelProperty(value = "所属区域", example = "华东地区")
    private String belongregion;
    @ApiModelProperty(value = "补贴标准", example = "1")
    private Integer subsidy;
    @ApiModelProperty(value = "启停标识", example = "0")
    private Integer startstopsign;
}
