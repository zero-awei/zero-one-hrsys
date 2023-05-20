package com.zeroone.star.project.dto.householdregistration_typestatuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("户口类型状态对象")
public class HouseholdDregistrationTypestatusListDTO {
    @ApiModelProperty(value="唯一 id",example = "1")
    private  Integer id;

    @ApiModelProperty(value="姓名",example = "bob")
    private  String name;
}
