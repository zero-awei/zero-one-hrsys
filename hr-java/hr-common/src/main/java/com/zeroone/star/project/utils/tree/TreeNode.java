package com.zeroone.star.project.utils.tree;

import lombok.Setter;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：用来定义一个树形节点的数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public class TreeNode implements Serializable {
    /**
     * 唯一ID
     */
    @Setter
    protected String tnId;
    /**
     * 节点父节点ID
     */
    @Setter
    protected String tnPid;
    /**
     * 节点深度
     */
    @Setter
    protected Integer tnDepth;
    /**
     * 节点包含的子节点
     */
    protected List<TreeNode> tnChildren;

    /**
     * 添加子节点，如果子类需要管理添加子节点操作可以通过重写此函数实现
     * @param child 子节点对象
     */
    public void addChild(TreeNode child) {
        // 判断子节点集合是否为空
        if (tnChildren == null) {
            tnChildren = new ArrayList<>();
        }
        // 添加子节点
        tnChildren.add(child);
    }

    /**
     * children类型转换
     * @return 返回转换后的集合
     * @param <T> 转换到的类型
     */
    protected <T> List<T> childrenElementTrans() {
        // 非空验证
        if (tnChildren == null || tnChildren.isEmpty()) {
            return null;
        }
        return tnChildren.stream().map(one -> (T) one).collect(Collectors.toList());
    }
}
