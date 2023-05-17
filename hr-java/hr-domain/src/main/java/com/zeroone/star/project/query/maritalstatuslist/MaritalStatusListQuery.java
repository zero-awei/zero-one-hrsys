package com.zeroone.star.project.query.maritalstatuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("员工婚姻状态查询")
public class MaritalStatusListQuery extends PageQuery {

    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;

}
