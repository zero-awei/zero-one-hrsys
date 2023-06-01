package com.zeroone.star.project.dto.orgmanager;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.*;
import java.util.Date;

/**
 * 描述：修改指定部门基本信息数据对象
 * 文件名：ModifyDeptInfoDTO
 * 创建者：rqs
 * 创建时间：2023/5/19 20:18
 */
@ApiModel("修改指定部门信息数据对象")
@Data
@TableName("t_srforgsector")
public class ModifyDeptInfoDTO {
    @ApiModelProperty(value = "部门标识",example = "46452940650577920")
    @TableField(value = "orgsectorid",update = "false")
    private String orgsectorid;

    @ApiModelProperty(value = "排序",example = "1")
    @NotNull(message = "排序不能为空")
    @Min(value = 0, message = "排序必须大于等于0")
    @TableField(value = "ordervalue")
    private Integer ordervalue;

    @ApiModelProperty(value = "名称",example = "01星球图灵院进阶项目j2小组")
    @TableField(value = "orgsectorname")
    @NotBlank(message = "名称不能为空")
    @Size(min = 1, max = 50, message = "名称长度必须在1~50之间")
    private String orgsectorname;

    @NotBlank(message = "编号不能为空")
    @Pattern(regexp ="[a-zA-Z0-9]{1,10}", message = "编号必须由1~10位字母或数字组成")
    @ApiModelProperty(value = "编号",example = "Hirqs")
    @TableField(value = "orgcode")
    private String orgcode;

    @Size(max = 10, message = "简称长度不能超过10")
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

    @ApiModelProperty(value = "编制控制",example = "10")//柔性:10 刚性:20
    @TableField(value = "gkjz")
    private String gkjz;

    @ApiModelProperty(value = "编制人数",example = "5")
    @Min(value = 0, message = "编制人数必须大于等于0")
    @TableField(value = "bmbzrs")
    private Integer bmbzrs;

    @ApiModelProperty(value = "启停标识",example = "1")//0：停用 1：启用
    @TableField(value = "startstopsign")
    @NotBlank(message = "启停标识不能为空")
    private String startstopsign;

    @ApiModelProperty(value = "所属OU",example = "欣苑")
    @TableField(value = " ")
    private String belongou;
}
