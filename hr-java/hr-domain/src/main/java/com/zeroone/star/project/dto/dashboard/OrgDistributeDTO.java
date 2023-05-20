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
    @ApiModelProperty(value = "组织标识", example = "020369F7-AFE6-4014-82D9-30915844D604")
    private String orgId;
    @ApiModelProperty(value = "组织名称", example = "湖南公司")
    private String orgName;
    @ApiModelProperty(value = "组织人数", example = "2")
    private Integer orgCount;
}
