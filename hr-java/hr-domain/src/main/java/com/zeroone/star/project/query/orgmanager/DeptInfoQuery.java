package com.zeroone.star.project.query.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：查询指定部门信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@Data
@ApiModel("查询指定部门信息")
public class DeptInfoQuery {
    @ApiModelProperty(value = "部门ID", example = "026E94BF-54F6-48E2-9C0E-599AE820DEFC")
    private String deptId;
}
