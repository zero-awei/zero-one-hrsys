package com.zeroone.star.project.query.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：导出指定部门考勤地址查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@Data
@ApiModel("导出指定部门考勤地址查询对象")
public class ExportAttendanceAddressQuery {
    @NotBlank(message = "部门ID不能为空")
    @ApiModelProperty(value = "部门ID", example = "402AF7C8-B205-455D-95F3-5D7275994199", required = true)
    private String departmentId;
}
