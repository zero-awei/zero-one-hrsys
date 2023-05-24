package com.zeroone.star.project.dto.orgmanager;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
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
@TableName("t_orgsector")
public class OrgsectorDTO {
    @ApiModelProperty(value = "排序",example = "1")
    @TableField(value = "ordervalue")
    private Integer ordervalue;
    @ApiModelProperty(value = "名称",example = "01星球图灵院进阶项目j2小组")
    @TableField(value = "orgsectorname")
    private String orgsectorname;
    @ApiModelProperty(value = "编号",example = "Hirqs")
    @TableField(value = "orgcode")
    private String orgcode;
    @ApiModelProperty(value = "简称",example = "j2")
    @TableField(value = "shortname")
    private String shortname;
    @ApiModelProperty(value = "类型",example = "机关部门")
    @TableField(value = "bmlx")
    private String bmlx;
    @ApiModelProperty(value = "所属组织",example = "薇欧拉")
    @TableField(value = "orgname")
    private String orgname;
    @ApiModelProperty(value = "所属区域",example = "华东地区") //10
    @TableField(value = "belongregion")
    private String belongregion;
    @ApiModelProperty(value = "补贴标准",example = "A类地区")// t_ormqygl
    @TableField(value = "qy")
    private String qy;
    @ApiModelProperty(value = "编制控制",example = "1")//柔性:1 刚性:2
    @TableField(value = "bzkz")
    private Integer bzkz;
    @ApiModelProperty(value = "编制人数",example = "5")
    @TableField(value = "bmbzrs")
    private Integer bmbzrs;
    @ApiModelProperty(value = "启停标识",example = "1")//0：停用 1：启用
    @TableField(value = "startstopsign")
    private String startstopsign;
    @ApiModelProperty(value = "所属OU",example = "欣苑")
    @TableField(value = "belongou")
    private String belongou;
}
