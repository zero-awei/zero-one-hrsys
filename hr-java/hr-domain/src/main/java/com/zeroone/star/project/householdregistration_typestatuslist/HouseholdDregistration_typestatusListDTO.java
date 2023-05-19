package com.zeroone.star.project.householdregistration_typestatuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 22:05
 * @since JDK8
 */
@Data
@ApiModel("户口类型状态对象")
public class HouseholdDregistration_typestatusListDTO {
    @ApiModelProperty(value="唯一 id",example = "1")
    private  Integer id;

    @ApiModelProperty(value="姓名",example = "bob")
    private  String name;
}
