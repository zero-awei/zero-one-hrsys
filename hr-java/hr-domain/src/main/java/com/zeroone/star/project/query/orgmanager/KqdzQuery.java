package com.zeroone.star.project.query.orgmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * 描述：查询指定部门考勤地址列表（分页查询）数据对象
 * 文件名：KqdzQuery
 * 创建者：rqs
 * 创建时间：2023/5/20 0:00
 */
@Data
@ApiModel("查询指定部门考勤地址列表（分页查询）数据对象")
public class KqdzQuery extends PageQuery {
    @ApiModelProperty(value = "要修改信息的部门编码",example = "2123")
    private String orgCode;
}
