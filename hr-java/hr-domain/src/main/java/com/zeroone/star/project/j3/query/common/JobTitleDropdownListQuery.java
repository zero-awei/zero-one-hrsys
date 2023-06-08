package com.zeroone.star.project.j3.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：职务信息查询条件
 * </p>
 * <p>版权：&copy;2023 wh</p>
 * <p>地址：</p>
 *
 * @version 1.0
 * @Author 18385
 * @Date 2023/5/19 0:08
 */

@EqualsAndHashCode()
@Data
@ApiModel("岗位下拉列表查询条件")
public class JobTitleDropdownListQuery {
	@ApiModelProperty(value = "组织名称", example = "XXX公司")
	private String ormorinfoname;

	@ApiModelProperty(value = "部门名称", example = "人力资源部")
	private  String  ormorgsectorname;

	@ApiModelProperty(value = "职务名称", example = "部门经理")
	private  String  zwlx;
}

