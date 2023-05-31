package com.zeroone.star.project.dto.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
  * @author：letian
  * @date  2023/5/18
  * @description：岗位分类数据对象
  * @version: 1.0
*/
@Data
@ApiModel("岗位分类数据对象")
public class PostTypeDTO {
    @ApiModelProperty(value = "岗位分类ID", example = "1")
    private String id;
    @ApiModelProperty(value = "岗位分类", example = "党内")
    private String postType;
}
