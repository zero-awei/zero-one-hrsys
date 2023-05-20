package com.zeroone.star.project.query.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
  * @author：letian
  * @date  2023/5/20
  * @description：部门查询对象
  * @version: 1.0
*/
@Data
@ApiModel("部门数据传输对象")
public class DeptQuery {
    @ApiModelProperty(value = "部门标识id", example = "7874AED2-5E83-4A0E-828A-0B88ED020599")
    private String orgSectorId;
}
