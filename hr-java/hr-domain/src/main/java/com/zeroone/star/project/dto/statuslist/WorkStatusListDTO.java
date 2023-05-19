package com.zeroone.star.project.dto.statuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 9:48
 */
@Data
@ApiModel("员工工作状态对象")
public class WorkStatusListDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "工作状态",example = "在职")
    private String gzzt;
}
