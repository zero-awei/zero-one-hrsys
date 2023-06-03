package com.zeroone.star.project.j3.dto.orgmanager;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Date;
import java.time.LocalDateTime;

@Data
@ApiModel("职务信息传输数据对象")
public class JobTitleDTO {

    @ApiModelProperty(value = "工作职务编码",example = "101")
    private String fglx; // 工作职务编码
    @ApiModelProperty(value = "职务名称",example = "总规划师")
    private String ormdutyname; // 职务名称
    @ApiModelProperty(value = "职务序号",example = "3")
    private int xh; // 职务序号
    @ApiModelProperty(value = "职务标识",example = "039bb636-099a-4deb-bf9b-c9b865e35e0f")
    private String ormdutyid; // 职务标识
    @ApiModelProperty(value = "更新日期",example = "2023-05-31 13:40:49")
    private String updatedate; // 更新日期
}
