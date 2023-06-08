package com.zeroone.star.project.vo.login;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.List;

/**
 * <p>
 * 描述：树状菜单显示数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
public class MenuTreeVO extends TreeNode {

    @ApiModelProperty(value = "序号", example = "1")
    private String id;
    @ApiModelProperty(value = "菜单名称", example = "主页")
    private String Text;
    @ApiModelProperty(value = "图标", example = "dashboard")
    private String icon;
    @ApiModelProperty(value = "路由地址", example = "/dashboard")
    private String href;
    @ApiModelProperty(value = "父级菜单编号", example = "0")
    private String pid;
    @ApiModelProperty(value = "节点包含的子节点")
    public List<MenuTreeVO> getChildren() {
        return childrenElementTrans();
    }
}
