package com.zeroone.star.project.j3.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：学历类型查询条件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */

@EqualsAndHashCode()
@Data
@ApiModel("查询单个字段")
public class EducationTypeQuery {
    @NotBlank(message = "查询字段名不能为空")
    @ApiModelProperty(value = "查询单个字段(学历)", example = "829D2BC3-6987-45E4-BFC9-18E423248218")
    private  String code;
}
