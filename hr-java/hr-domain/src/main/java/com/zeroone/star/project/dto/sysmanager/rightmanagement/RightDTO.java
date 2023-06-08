package com.zeroone.star.project.dto.sysmanager.rightmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;


/**
 * The {@link RightDTO}
 *
 * @author authoralankay
 */
@Data
@ApiModel("权限修改")
public class RightDTO {

    @ApiModelProperty(value = "唯一编号",example = "自动生成")
    private String id;

    @ApiModelProperty(value = "权限名称",example = "增加权限")
    private String name;

    @ApiModelProperty(value = "链接地址", example = "/add-right")
    private String linkUrl;

    @ApiModelProperty(value = "显示级别", example = "1")
    private Integer priority;

    @ApiModelProperty(value = "父权限 id", example = "0")
    private String parentRightId;

    @ApiModelProperty(value = "层次", example = "1")
    private Integer level;

    @ApiModelProperty(value = "描述", example = "增加权限")
    private String description;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;

    @ApiModelProperty(value = "创建人", example = "自动生成")
    private String creator;

    @ApiModelProperty(value = "创建时间", example = "自动生成")
    private Date createTime;

    @ApiModelProperty(value = "更新时间",example = "自动生成")
    private Date updateTime;

}
