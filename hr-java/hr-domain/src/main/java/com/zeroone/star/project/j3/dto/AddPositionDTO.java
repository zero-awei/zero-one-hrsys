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
 * @date 2023/5/22 16:34
 */


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：新增职务DTO
 * </p>
 * <p>版权：&copy;tomcatcc </p>
 * <p>地址：</p>
 * @Author tomcatcc
 * @version 1.0.0
 */
@Data
@ApiModel("新增职务")
public class AddPositionDTO {

    @ApiModelProperty(value = "编号",example = "[\"1\",\"2\"]")
    private List<String> SerialNumber;
    @ApiModelProperty(value = "职务编码" ,example = "[\"F429\",\"J83C\"]")
    private List<String> JobNumber;
    @ApiModelProperty(value = "职务名称" ,example = "[\"部门经理\",\"项目经理\"]")
    private List<String> JobTitle;
    @ApiModelProperty(value = "更新人" ,example = "[\"tocatcc\",\"tocki\"]")
    private List<String> UpdatedMan;
    @ApiModelProperty(value = "更新时间" ,example = "[\"2023-04-22 00:01:47\",\"2023-04-21 09:01:37\"]")
    private List<String> UpdateTime;
}
