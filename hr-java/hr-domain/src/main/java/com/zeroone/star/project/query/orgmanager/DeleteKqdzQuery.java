package com.zeroone.star.project.query.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：删除指定部门考勤地址信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author C.C.
 * @version 1.0.0
 */
@Data
@ApiModel("删除指定部门考勤地址信息")
public class DeleteKqdzQuery {
    @ApiModelProperty(value = "部门名称", example = "市场营销部")
    private String name;
}
