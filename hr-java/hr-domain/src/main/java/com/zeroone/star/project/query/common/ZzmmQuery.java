package com.zeroone.star.project.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：政治面貌下拉列表数据对象
 * 文件名：ZzmmQuery
 * 创建者：rqs
 * 创建时间：2023/5/19 23:05
 */
@ApiModel("政治面貌下拉列表数据对象")
@Data
public class ZzmmQuery {
    @ApiModelProperty(value = "政治面貌",example = "1")
    private String zzmm;
//    @ApiModelProperty(value = "入党时间",example = "2023-05-04")
//    private String rdsj;
//    @ApiModelProperty(value = "入团时间",example = "2023-05-04")
//    private String rtsj;
}
