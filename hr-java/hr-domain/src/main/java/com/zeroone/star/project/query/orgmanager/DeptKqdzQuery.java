package com.zeroone.star.project.query.orgmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：查询指定部门考勤地址列表（分页查询）数据对象
 * 文件名：KqdzQuery
 * 创建者：rqs
 * 创建时间：2023/5/20 0:00
 */
@Data
@ApiModel("查询指定部门考勤地址列表（分页查询）数据对象")
public class DeptKqdzQuery extends PageQuery {
    @ApiModelProperty(value = "部门ID",example = "21240BC7-5A3F-4823-A2BD-F2CD8331D95C")
    private String ormorgsectorid;
}
