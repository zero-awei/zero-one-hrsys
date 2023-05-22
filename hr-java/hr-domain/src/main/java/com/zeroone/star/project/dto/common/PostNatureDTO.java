package com.zeroone.star.project.dto.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
  * @author：letian
  * @date  2023/5/18
  * @description：岗位性质数据对象
  * @version: 1.0
*/
@Data
@ApiModel("岗位性质数据对象")
public class PostNatureDTO {
    @ApiModelProperty(value = "岗位标识", example = "1ED4D76B-8470-405C-90CA-147A399B3050")
    private String ormPostId;
    @ApiModelProperty(value = "岗位性质", example = "10")
    private String jobDesc;
}
