package com.zeroone.star.project.query.sample;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：示例查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("示例查询对象")
public class SampleQuery extends PageQuery {
    @NotBlank(message = "用户名不能为空")
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
}
