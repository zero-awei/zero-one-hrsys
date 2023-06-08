package com.zeroone.star.project.j3.dto;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;

/**
 * ClassName: AddOrgInfoDTO
 * Description: 对应 DAO 的组织信息DTO
 *
 * @Author LR
 * @Create 2023/5/27 19:14
 * @Version 1.0
 */
@Data
@ApiModel("添加组织传输对象")
public class AddOrgInfoDTO {
    @ApiModelProperty(value = "组织ID（前端生成传入）", example = "020369F7-AFE6-4014-82D9-30915844D604x", required = true)
    private String orgid;

    @ApiModelProperty(value = "组织名称", example = "湖南公司", required = true)
    private String orgname;

    @ApiModelProperty(value = "组织编号", example = "207", required = true)
    private String orgcode;

    @ApiModelProperty(value = "组织简称", example = "湖南公司", required = true)
    private String shortname;

    @ApiModelProperty(value = "上级组织ID", example = "24D90D8F-7496-4244-8517-A2EB3B688A4B", required = true)
    private String porgid;

    @ApiModelProperty(value = "组织排序编号", example = "1", required = true)
    private String px;

    @ApiModelProperty(value = "所属区域(id)", example = "20", required = true)
    private String gsss;

    @ApiModelProperty(value = "补贴标准(id)", example = "25E573E8-870D-44E1-B291-DF09CBF81E52", required = true)
    private String btqy;

    @ApiModelProperty(value = "所属OU", example = "xxxxx")
    private String ssou;

    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @ApiModelProperty(value = "组织创建时间", example = "2021-01-01", required = true)
    private Date zzcjsj;

    @ApiModelProperty(value = "组织性质", example = "10")
    private String legalentity;

    @ApiModelProperty(value = "启停标识（0/1->停/启）", example = "1", required = true)
    private String startstopsign;

    @ApiModelProperty(value = "对应OU", example = "")
    private String correspondingorg;

}
