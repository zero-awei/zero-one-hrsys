package com.zeroone.star.project.query.ethnic_typestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;



@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("民族类型状态查询")
public class EthnicTypeStatusListQuery extends PageQuery {
    @ApiModelProperty(value = "name",example = "Bob")
    private  String name;
}
