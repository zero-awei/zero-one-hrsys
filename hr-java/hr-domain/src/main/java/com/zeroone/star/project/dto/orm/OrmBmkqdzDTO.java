package com.zeroone.star.project.dto.orm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 15:39
 */
@Data
@ApiModel("部门考勤地址对象")
public class OrmBmkqdzDTO {
    @NotBlank(message = "部门ID不能为空")
    @ApiModelProperty(value = "部门唯一标识",example = "402AF7C8-B205-455D-95F3-5D7275994199")
    private String departmentId;


    @ApiModelProperty(value = "部门考勤地址名",example = "XX市XX区XX路XX号")
    private String departmentkqdz;

}
