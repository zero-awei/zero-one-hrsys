package com.zeroone.star.project.dto.orgmanager;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 描述：查询指定部门考勤地址列表（分页查询）数据对象
 * 文件名：DeptKqdzVO
 * 创建者：rqs
 * 创建时间：2023/5/20 0:09
 */
@ApiModel("查询指定部门考勤地址列表（分页查询）数据对象")
@Data
public class DeptKqdzDTO {
    @ApiModelProperty(value = "部门地址", example = "宜昌")
    @ExcelProperty(value = "部门地址", index = 0)
    private String ormbmkqdzname;
    @ApiModelProperty(value = "考勤范围", example = "西陵区")
    @ExcelProperty(value = "考勤范围", index = 1)
    private String attendancerange;
    @ApiModelProperty(value = "更新人", example = "rqs")
    @ExcelProperty(value = "更新人", index = 2)
    private String updateman;
    @ApiModelProperty(value = "更新时间", example = "2023-05-12 00:00:00")
    @ExcelProperty(value = "更新时间", index = 3)
    private String updatedate;
}
