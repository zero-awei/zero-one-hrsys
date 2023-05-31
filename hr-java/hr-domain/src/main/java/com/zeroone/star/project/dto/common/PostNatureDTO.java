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
    @ApiModelProperty(value = "岗位性质ID", example = "1")
    private String id;
    @ApiModelProperty(value = "岗位性质", example = "标准工时制")
    private String postNature;
}
