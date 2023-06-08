package com.zeroone.star.project.query.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：学历分布数据对象
 * 文件名：EducationQuery
 * 创建者：rqs
 * 创建时间：2023/5/18 21:20
 */
@ApiModel("学历分布数据对象")
@Data
public class EducationQuery {
    @ApiModelProperty(value = "学历名称",example = "博士")
    private String educationname;
    @ApiModelProperty(value = "人数",example = "5")
    private Integer count;
}
