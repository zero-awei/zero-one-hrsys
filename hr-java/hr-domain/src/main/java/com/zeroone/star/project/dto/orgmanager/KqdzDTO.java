package com.zeroone.star.project.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：部门考勤地址传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author C.C.
 * @version 1.0.0
 */

@Data
@ApiModel("删除指定部门考勤地址信息")
public class KqdzDTO {
    @ApiModelProperty(value = "部门地址",example ="宜昌")
    private String ormbmkqdzname;
    @ApiModelProperty(value = "考勤范围",example ="西陵区")
    private String attendancerange;
    @ApiModelProperty(value = "更新人", example = "cc")
    private String updateman;
    @ApiModelProperty(value = "更新时间", example = "2023-05-12 00:00:00")
    private String updatedate;
}
