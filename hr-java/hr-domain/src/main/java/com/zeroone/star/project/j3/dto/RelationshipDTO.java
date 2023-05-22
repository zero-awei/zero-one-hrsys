package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

import java.util.List;

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
@ApiModel("与本人关系")
public class RelationshipDTO {

    @ApiModelProperty(value = "关系类型" , example = "[\"父子\",\"母子\"]")
    private List<String> Relationship;
}
