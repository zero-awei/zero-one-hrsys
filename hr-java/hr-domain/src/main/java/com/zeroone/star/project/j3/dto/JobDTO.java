package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;

/**
 * ClassName: JobDTO
 * Description: 职务详细传输对象（防API报错，暂未实例）
 *
 * @Author LR
 * @Create 2023/5/19 11:50
 * @Version 1.0
 */

@ApiModel("职务详细传输对象")
@Data
public class JobDTO {
    @ApiModelProperty(value = "序号",example = "1")
    private int xh;
    @ApiModelProperty(value = "职务编码",example = "2213")
    private String fglx;
    @ApiModelProperty(value = "职务标识",example = "唯一字段，不展示")
    private String ormdutyId;
    @ApiModelProperty(value = "职务名称",example = "技术员")
    private String ormdutyName;
    @ApiModelProperty(value = "更新人",example = "管理员")
    private String updateMan;
    @ApiModelProperty(value = "更新日期",example = "2023-05-17 12:14:15")
    private Date updateTime;
}
