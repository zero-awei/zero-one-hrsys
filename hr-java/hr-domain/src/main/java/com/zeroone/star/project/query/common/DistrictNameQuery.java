package com.zeroone.star.project.query.common;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：区县名称下拉列表查询对象
 * 创建者：浅墨
 */
@ApiModel("区县名称下拉列表查询对象")
@Data
public class DistrictNameQuery {
    @ApiModelProperty(value = "所属城市", example = "江西省")
    private String cityName;
}
