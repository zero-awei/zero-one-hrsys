package com.zeroone.star.project.dto.orm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 15:39
 */
@Data
@Getter
@Setter
@ApiModel("部门考勤地址对象")
public class OrmBmkqdzDTO {
    @NotBlank(message = "部门ID不能为空")
    @ApiModelProperty(value = "部门唯一标识",example = "175af12e41e1c90d9baf82b9cb16f7e3")
    private String departmentId;


    @ApiModelProperty(value = "部门考勤地址名",example = "XX市XX区XX路XX号")
    private String departmentkqdz;


    @ApiModelProperty(value = "更新人",example = "ibzadmin")
    private String updateman;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

}
