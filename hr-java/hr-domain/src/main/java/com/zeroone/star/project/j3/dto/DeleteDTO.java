package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：删除传输数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/20 10:15
 */
@ApiModel("删除传输数据对象")
@Data
public class DeleteDTO {
    @ApiModelProperty(value = "删除ID列表",example = "[\"dddd\",\"aaaa\"]")
    private List<String> ids;
}
