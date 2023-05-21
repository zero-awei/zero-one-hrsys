package com.zeroone.star.project.j3.dto;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

import lombok.Data;

/**
 * <p>
 * 描述：
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/19 16:52
 */
@ApiModel("导入职务数据传输对象")
@Data
public class AllJobsDTO {
    @ApiModelProperty(value = "序号", example = "1")
    private int xh;
    @ApiModelProperty(value = "职务编码", example = "222")
    private Integer fglx;
    @ApiModelProperty(value = "职务名称", example = "总规划师")
    private String ormdutyname;

}
