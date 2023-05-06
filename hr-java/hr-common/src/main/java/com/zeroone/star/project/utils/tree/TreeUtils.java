package com.zeroone.star.project.utils.tree;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：树形数据构建工具类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public class TreeUtils {

    /**
     * 将列表数据转换成树状数据
     * @param list   列表数据
     * @param mapper 数据转换节点数据匹配接口
     * @param <S>    输入数据类型一般是DO
     * @param <T>    结果数据类型一般是DTO
     * @return 返回树状数据列表
     */
    public static <S, T> List<T> listToTree(List<S> list, TreeNodeMapper<S> mapper) {
        // 1 把集合中的数据转换为树形节点数据
        List<TreeNode> nodes = new ArrayList<>();
        for (S row : list) {
            TreeNode node = mapper.objectMapper(row);
            nodes.add(node);
        }
        // 2 构建一个具有层次结构的树
        List<T> tree = new ArrayList<>();
        // 3 循环获取根节点
        for (TreeNode node : nodes) {
            if (null == node.tnPid) {
                node.setTnDepth(0);
                tree.add((T) node);
                // 查找子节点
                findChildNodes(node, nodes);
            }
        }
        return tree;
    }

    /**
     * 查找并设置指定父节点的对应子节点
     * @param parentNode 父节点
     * @param nodes      节点集合
     */
    private static void findChildNodes(TreeNode parentNode, List<TreeNode> nodes) {
        for (TreeNode child : nodes) {
            // 找到子节点
            if (parentNode.tnId.equals(child.tnPid)) {
                // 设置子节点的相关层次数据
                child.setTnDepth(parentNode.tnDepth + 1);
                // 将子节点添加到父节点的子节点集合中
                parentNode.addChild(child);
                // 查找子节点包含的子节点
                findChildNodes(child, nodes);
            }
        }
    }
}
