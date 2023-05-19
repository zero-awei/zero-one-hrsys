package com.zeroone.star.project.query.city_namestatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 22:24
 * @since JDK8
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("城市名称状态查询")
public class City_NameStatusListQuery extends PageQuery {
    @ApiModelProperty(name = "姓名",example = "Bob")
    private  String name;
}
