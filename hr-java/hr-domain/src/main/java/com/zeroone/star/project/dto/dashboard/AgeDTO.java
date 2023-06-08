package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：年龄分布数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author C.C.
 * @version 1.0.0
 */

@ApiModel("年龄传输对象")
@Data
public class AgeDTO {
    @ApiModelProperty(value = "年龄区间", example = "20-30")
    private String ageRange;
    @ApiModelProperty(value = "年龄人数", example = "10")
    private Integer ageNum;
}
