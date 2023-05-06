package com.zeroone.star.project.dto.cpp;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：示例传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@ApiModel("C++示例传输数据对象")
public class SampleDTO {
    @ApiModelProperty(value = "编号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "姓名", example = "C++")
    private String name;
    @ApiModelProperty(value = "年龄", example = "99")
    private Integer age;
    @ApiModelProperty(value = "性别", example = "男")
    private String sex;
}
