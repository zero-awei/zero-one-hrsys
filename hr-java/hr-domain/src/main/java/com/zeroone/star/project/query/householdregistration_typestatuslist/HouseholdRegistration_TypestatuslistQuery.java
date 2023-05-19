package com.zeroone.star.project.query.householdregistration_typestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 22:12
 * @since JDK8
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("户口类型状态查询")
public class HouseholdRegistration_TypestatuslistQuery extends PageQuery {
    @ApiModelProperty(value = "姓名",example = "Bob")
    private  String name;

}
