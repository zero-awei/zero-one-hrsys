package com.zeroone.star.project.query.statuslist;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 9:45
 */

@ApiModel("员工工作状态查询")
@Data
@EqualsAndHashCode(callSuper = true)
public class WorkStatusListQuery extends PageQuery {
    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;
}
