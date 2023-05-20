package com.zeroone.star.project.dto.city_namestatuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.NonNull;



@Data
@ApiModel("城市名称状态对象")
public class CityNameStatusListDTO {

    @ApiModelProperty(value="唯一 id",example = "1")
    private  Integer id;

    @ApiModelProperty(value="姓名",example = "bob")
    private  String name;
}
