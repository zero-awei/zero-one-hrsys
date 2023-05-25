package com.zeroone.star.project.j3.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：职务下拉列表查询条件
 * </p>
 * <p>版权：&copy;2023 </p>
 * <p>地址：</p>
 *
 * @Author 18385
 * @version 1.0.0
 * @Date 2023/5/22 22:00
 */

@EqualsAndHashCode()
@Data
@ApiModel("职务下拉列表查询条件")
public class PositionTitleDropdownListQuery {
	@ApiModelProperty(value = "组织名称", example = "XXX公司")
	private String ormorinfoname;

	@ApiModelProperty(value = "部门名称", example = "人力资源部")
	private String  ormorgsectorname;
}

