package com.zeroone.star.project.query.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：导出部门查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@Data
@ApiModel("导出部门查询对象")
public class ExportDepartmentsQuery {
    @ApiModelProperty(value = "部门名称", example = "市场营销部")
    private String departmentName;
}
