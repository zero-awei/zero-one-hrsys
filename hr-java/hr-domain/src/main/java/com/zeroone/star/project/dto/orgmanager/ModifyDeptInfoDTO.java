package com.zeroone.star.project.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * 描述：修改指定部门信息数据对象
 * 文件名：ModifyDeptInfoDTO
 * 创建者：rqs
 * 创建时间：2023/5/19 20:18
 */
@ApiModel("修改指定部门信息数据对象")
@Data
public class ModifyDeptInfoDTO {
    @ApiModelProperty(value = "要修改信息的部门编码",example = "2123")
    private String orgCode;
}
