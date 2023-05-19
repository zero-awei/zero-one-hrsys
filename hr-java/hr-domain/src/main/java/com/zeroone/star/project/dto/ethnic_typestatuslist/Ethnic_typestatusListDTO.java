package com.zeroone.star.project.dto.ethnic_typestatuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 22:03
 * @since JDK8
 */
@Data
@ApiModel("名族类型状态对象")
public class Ethnic_typestatusListDTO {
    @ApiModelProperty(value="唯一 id",example = "1")
    private  Integer id;

    @ApiModelProperty(value="姓名",example = "bob")
    private  String name;
}
