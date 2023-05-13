package com.zeroone.star.project.dto.test;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@ApiModel("测试查询对象")
public class TestDTO {
    @ApiModelProperty(value = "唯一编号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
}
