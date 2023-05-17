package com.zeroone.star.project.dto.maritalstatuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("员工婚姻状态对象")
public class MaritalStatusListDTO {

    @ApiModelProperty(value = "唯一编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;


}
