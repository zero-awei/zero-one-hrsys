package com.zeroone.star.project.j3.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * ClassName: SectorNameQuery
 * Description: 通过组织id和部门名称查询部门名称
 *
 * @Author LR
 * @Create 2023/5/21 16:21
 * @Version 1.0
 */
@EqualsAndHashCode()
@Data
@ApiModel("通过组织id和部门名称查询部门名称")
public class SectorNameQuery {
    @ApiModelProperty(value = "组织id", example = "A2493B92-BADB-4922-9FCF-A569D905868F")
    private String orgId;
    @ApiModelProperty(value = "部门名称", example = "人力资源部")
    private String name;
}
