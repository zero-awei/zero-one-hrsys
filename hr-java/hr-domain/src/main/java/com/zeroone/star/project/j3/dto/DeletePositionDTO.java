package com.zeroone.star.project.j3.dto;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/22 16:35
 */


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：删除职务DTO
 * </p>
 * <p>版权：&copy;tomcatcc </p>
 * <p>地址：</p>
 * @Author tomcatcc
 * @version 1.0.0
 */

@Data
@ApiModel("删除职务")
public class DeletePositionDTO {

    @ApiModelProperty(value = "职务ID",example = "[\"aaa\",\"bbb\"]")
    private List<String> positionId;
}
