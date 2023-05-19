package com.zeroone.star.project.dto.department_typestatuslist;

/**
 * @author abner
 * @version 1.0
 */
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@Data
@ApiModel("部门类型状态对象")
public class DepartmentTypeStatusListDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;
}
