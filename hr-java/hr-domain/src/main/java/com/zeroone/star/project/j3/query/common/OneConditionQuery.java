package com.zeroone.star.project.j3.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

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
@ApiModel("查询单个字段")
public class OneConditionQuery {
	@NotBlank(message = "查询字段名不能为空")
	@ApiModelProperty(value = "查询单个字段", example = "zw(职务)")
	private  String condition;
}

