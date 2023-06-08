package com.zeroone.star.project.query.sysmanager.rightmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：权限查询数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("权限分页查询")
public class RightQuery extends PageQuery {

    @ApiModelProperty(value = "权限名称",example = "增加权限")
    private String name;

    @ApiModelProperty(value = "链接地址", example = "/add-right")
    private String linkUrl;

    @ApiModelProperty(value = "显示级别", example = "1")
    private Integer priority;

    @ApiModelProperty(value = "层次", example = "1")
    private Integer level;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;
}
