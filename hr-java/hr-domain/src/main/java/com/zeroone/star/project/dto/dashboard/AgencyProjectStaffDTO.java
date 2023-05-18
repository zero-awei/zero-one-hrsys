package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：机关和项目人员传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@ApiModel("机关和项目人员传输对象")
@Data
public class AgencyProjectStaffDTO {
    @ApiModelProperty(value = "人员数量", example = "1")
    private Integer countNum;
    @ApiModelProperty(value = "机关类型", example = "局机关")
    private String ormType;
}
