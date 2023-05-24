package com.zeroone.star.project.j3.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * ClassName: JobByNameQuery
 * Description: 通过名称关键字查询职务
 *
 * @Author LR
 * @Create 2023/5/20 14:40
 * @Version 1.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("关键字查询职务对象")
public class JobByNameQuery extends PageQuery {
    @ApiModelProperty(value = "关键字", example = "技术")
    private String name;
}
