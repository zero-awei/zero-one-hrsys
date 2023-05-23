package com.zeroone.star.project.query.householdregistration_typestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("户口类型状态查询")
public class HouseholdRegistrationTypestatuslistQuery extends PageQuery {
    @ApiModelProperty(value = "姓名",example = "Bob")
    private  String name;

}
