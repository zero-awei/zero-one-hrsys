package com.zeroone.star.project.query.ethnic_typestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 22:15
 * @since JDK8
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("民族类型状态查询")
public class Ethnic_TypeStatusListQuery extends PageQuery {
    @ApiModelProperty(value = "name",example = "Bob")
    private  String name;
}
