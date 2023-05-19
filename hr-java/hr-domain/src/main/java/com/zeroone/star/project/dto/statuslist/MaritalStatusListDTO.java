package com.zeroone.star.project.dto.statuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("员工婚姻状态对象")
public class MaritalStatusListDTO {

    @ApiModelProperty(value = "唯一编号",example = "1")
    private Integer id;


    @ApiModelProperty(value = "婚姻状态",example = "未婚")
    private String hyzt;

}
