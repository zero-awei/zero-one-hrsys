package com.zeroone.star.project.dto.statuslist;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 员工状态列表
 */
@Data
@ApiModel("员工状态列表")
public class StatusListDto {
    @ApiModelProperty(value = "唯一编号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;

}
