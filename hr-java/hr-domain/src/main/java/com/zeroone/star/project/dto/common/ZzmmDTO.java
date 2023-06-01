package com.zeroone.star.project.dto.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：政治面貌下拉列表数据对象
 * 文件名：ZzmmDTO
 * 创建者：rqs
 * 创建时间：2023/5/22 22:24
 */
@ApiModel("政治面貌下拉列表数据对象")
@Data
public class ZzmmDTO {
    @ApiModelProperty(value = "政治面貌编号",example = "1")
    private Integer id;
    @ApiModelProperty(value = "政治面貌名称",example = "中共党员")
    private String name;
}
