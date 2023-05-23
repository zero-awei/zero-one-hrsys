package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
  * @author：letian
  * @date  2023/5/22
  * @description：组织人数数据对象
  * @version: 1.0
*/
@Data
@ApiModel("组织人数信息数据对象")
public class OrgEmployeeCountDTO {
    @ApiModelProperty(value = "组织标识", example = "020369F7-AFE6-4014-82D9-30915844D604")
    private String organizationId;
    @ApiModelProperty(value = "员工名称", example = "张**")
    private String employeeName;
}
