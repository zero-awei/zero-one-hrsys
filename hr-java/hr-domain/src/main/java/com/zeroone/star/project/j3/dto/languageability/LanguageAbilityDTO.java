package com.zeroone.star.project.j3.dto.languageability;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("语言能力传输数据对象")
public class LanguageAbilityDTO {

    @ApiModelProperty(value = "语言能力标识",example = "101")
    private String languageId;
    @ApiModelProperty(value = "人员标识",example = "username")
    private String personId; // 人员信息标识
    @ApiModelProperty(value = "外语类型",example = "英语")
    private String languageType; // 外语类型
    @ApiModelProperty(value = "外语等级",example = "大学英语六级")
    private String languageLevel; // 外语等级

}
