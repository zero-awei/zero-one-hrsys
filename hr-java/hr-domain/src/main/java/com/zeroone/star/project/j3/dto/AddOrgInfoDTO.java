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
@ApiModel("添加组织信息传输对象")
public class AddOrgInfoDTO {
    @ApiModelProperty(value = "组织ID（前端生成传入）", example = "c3f3bc45b74", required = true)
    private String ormorginfoid;

    @ApiModelProperty(value = "组织名称", example = "XXX公司", required = true)
    private String ormorginfoname;

    @ApiModelProperty(value = "组织编号", example = "001", required = true)
    private String orgcode;

    @ApiModelProperty(value = "组织简称", example = "XXX", required = true)
    private String shortname;

    @ApiModelProperty(value = "上级组织ID", example = "1", required = true)
    private String porgid;

    @ApiModelProperty(value = "组织排序编号", example = "001", required = true)
    private String ordernum;

    @ApiModelProperty(value = "所属区域", example = "华东地区", required = true)
    private String belongregion;

    @ApiModelProperty(value = "补贴标准(id)", example = "3f3bc4", required = true)
    private String substandard;

    @ApiModelProperty(value = "所属OU", example = "1")
    private String ouid;

    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @ApiModelProperty(value = "组织启用时间", example = "2021-01-01", required = true)
    private Date createdate;

    @ApiModelProperty(value = "组织性质", example = "法人单位")
    private String orgtype;

    @ApiModelProperty(value = "启停标识", example = "启用", required = true)
    private String startstopsign;

    @ApiModelProperty(value = "对应OU", example = "001")
    private String porgsectorid;

}
