package com.zeroone.star.project.query.district_namestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("区(县)名称状态查询")
public class DistrictNameStatusListQuery extends PageQuery {
    @ApiModelProperty(name = "姓名",example = "Bob")
    private  String name;
}
