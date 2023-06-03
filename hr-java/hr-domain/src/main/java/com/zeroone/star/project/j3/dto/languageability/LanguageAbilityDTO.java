package com.zeroone.star.project.j3.dto.languageability;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("语言能力传输数据对象")
public class LanguageAbilityDTO {

    @ApiModelProperty(value = "语言能力标识",example = "101")
    private String pimlanguageabilityid;
    @ApiModelProperty(value = "人员标识",example = "66958E87-91A4-4DA8-8124-060E93B47EBE")
    private String pimpersonid; // 人员信息标识
    @ApiModelProperty(value = "语种",example = "英语")
    private String wyyz; // 外语类型
    @ApiModelProperty(value = "外语等级",example = "大学英语六级")
    private String wydj; // 外语等级
    @ApiModelProperty(value = "外语等级获取时间",example = "2020-10-15")
    private String wydjhqsj; // 获取时间
}
