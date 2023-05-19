package com.zeroone.star.project.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * 描述：新增部门数据对象
 * 文件名：DeptInfoDTO
 * 创建者：rqs
 * 创建时间：2023/5/19 20:18
 */
@ApiModel("新增部门数据对象")
@Data
public class DeptInfoDTO {
    @ApiModelProperty(value = "组织ID",example = "000000")
    private String ormOrgInfoId;
    @ApiModelProperty(value = "组织名称",example = "01星球图灵院进阶项目j2小组")
    private String ormOrgInfoName;
    @ApiModelProperty(value = "建立时间",example = "2023-05-19 20:37:48")
    private Date createDate;
    @ApiModelProperty(value = "建立人",example = "rqs")
    private String createMan;
    @ApiModelProperty(value = "更新时间",example = "2023-05-19 20:38:32")
    private Date updateDate;
    @ApiModelProperty(value = "更新人",example = "rqs")
    private String updateMan;
    @ApiModelProperty(value = "组织编码",example = "2123")
    private String orgCode;
    @ApiModelProperty(value = "组织简称",example = "21212")
    private String shortName;
    @ApiModelProperty(value = "组织排序编号",example = "1")
    private int orderNum;
    @ApiModelProperty(value = "组织类型",example = "")
    private String orgType;
    @ApiModelProperty(value = "组织类型释义",example = "")
    private String orgTypeName;
    @ApiModelProperty(value = "所属OU的组织ID",example = "1")
    private String ouId;
    @ApiModelProperty(value = "所属区域",example = "10")
    private String belongRegion;
    @ApiModelProperty(value = "补贴标准",example = "B类地区")
    private String substandard;
    @ApiModelProperty(value = "上级组织ID",example = "1")
    private String pOrgId;
    @ApiModelProperty(value = "ERP组织ID",example = "1")
    private String ormErpOrgId;
    @ApiModelProperty(value = "启停标识",example = "1")
    private int startStopSign;
    @ApiModelProperty(value = "岗位",example = "初级程序员")
    private String postInfo;
    @ApiModelProperty(value = "上级部门ID",example = "")
    private String pOrgSectorId;
}
