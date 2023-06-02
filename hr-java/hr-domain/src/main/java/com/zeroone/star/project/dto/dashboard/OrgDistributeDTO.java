package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
  * @author：letian
  * @date  2023/5/20
  * @description：组织分布数据对象
  * @version: 1.0
*/
@ApiModel("组织分布信息数据对象")
@Data
public class OrgDistributeDTO {
    @ApiModelProperty(value = "组织名称", example = "山东公司")
    private String orgName;
    @ApiModelProperty(value = "组织人数", example = "120")
    private Integer number;
}
