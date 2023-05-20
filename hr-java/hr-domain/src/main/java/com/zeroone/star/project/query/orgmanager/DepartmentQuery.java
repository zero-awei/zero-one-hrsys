package com.zeroone.star.project.query.orgmanager;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("部门管理查询")
public class DepartmentQuery extends PageQuery {
    @ApiModelProperty(value = "部门名称", example = "市场营销部")
    private String name;
}
