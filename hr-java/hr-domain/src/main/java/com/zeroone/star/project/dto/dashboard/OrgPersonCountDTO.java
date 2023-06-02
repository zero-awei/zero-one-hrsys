package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
  * @author：letian
  * @date  2023/6/2
  * @description：组织人数数据对象
  * @version: 1.0
*/
@ApiModel("组织人数信息数据对象")
@Data
public class OrgPersonCountDTO {
    @ApiModelProperty(value = "组织id", example = "5E86B4C2-7C97-4210-9001-AD70B6F7A930")
    private String ormOrgId;
    @ApiModelProperty(value = "组织人数", example = "120")
    private Integer personCount;
}
