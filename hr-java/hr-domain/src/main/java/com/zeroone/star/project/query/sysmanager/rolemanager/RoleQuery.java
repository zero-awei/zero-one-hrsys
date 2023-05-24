package com.zeroone.star.project.query.sysmanager.rolemanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：角色查询数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("角色分页查询")
public class RoleQuery extends PageQuery {

    @ApiModelProperty(value = "角色名称", example = "管理员")
    private String name;

    @ApiModelProperty(value = "关键词", example = "ADMIN")
    private String keyWord;

    @ApiModelProperty(value = "是否启用", example = "1")
    private Integer isEnable;
}
