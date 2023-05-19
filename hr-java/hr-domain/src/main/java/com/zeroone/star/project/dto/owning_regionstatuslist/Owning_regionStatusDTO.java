package com.zeroone.star.project.dto.owning_regionstatuslist;

/**
 * @author abner
 * @version 1.0
 */
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("所属区域状态对象")
public class Owning_regionStatusDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private Integer id;

    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;
}
