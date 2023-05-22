package com.zeroone.star.project.query.city_namestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("城市名称状态查询")
public class CityNameStatusListQuery extends PageQuery {
    @ApiModelProperty(name = "姓名",example = "Bob")
    private  String name;
}
