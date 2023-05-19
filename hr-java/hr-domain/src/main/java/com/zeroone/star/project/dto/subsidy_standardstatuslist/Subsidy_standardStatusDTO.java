package com.zeroone.star.project.dto.subsidy_standardstatuslist;

/**
 * @author abner
 * @version 1.0
 */
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("补贴标准状态对象")
public class Subsidy_standardStatusDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;
}
