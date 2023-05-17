package com.zeroone.star.project.query.statuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


/**
 *员工状态查询
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("员工状态查询")
public class StatusListQuery extends PageQuery {
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
}
