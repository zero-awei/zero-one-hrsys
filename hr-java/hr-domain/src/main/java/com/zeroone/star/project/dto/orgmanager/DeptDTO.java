package com.zeroone.star.project.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
  * @author：letian
  * @date  2023/5/18
  * @description：部门传输数据对象（DTO）
  * @version: 1.0
*/
@Data
@ApiModel("部门数据传输对象")
public class DeptDTO {
    @ApiModelProperty(value = "部门标识id", example = "7874AED2-5E83-4A0E-828A-0B88ED020599")
    private String orgSectorId;
    @ApiModelProperty(value = "部门名称name", example = "人力资源部")
    private String orgSectorName;
}
