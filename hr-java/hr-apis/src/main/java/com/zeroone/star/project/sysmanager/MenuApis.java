package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.constraints.NotBlank;


/**
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */

public interface MenuApis {
    /**
     * 描述：分页查询列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MenuDTO>> queryAll(MenuQuery query);

    /**
     * 添加菜单
     *
     * @param dto 菜单对象
     * @return 结果状态
     */
    JsonVO<Boolean> addMenu(MenuDTO dto);

    /**
     * 修改菜单
     *
     * @param dto 修改菜单
     * @return 结果状态
     */
    JsonVO<Boolean> modifyMenu(MenuDTO dto);

    /**
     * 删除菜单
     *
     * @param id 删除菜单
     * @return 结果状态
     */
    JsonVO<Boolean> removeMenu(@NotBlank(message = "id 不能为空")String id);

    /**
     * 描述：模糊查询
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MenuDTO>> queryLike(CommentQuery query);

    /**
     * 修改状态
     * @param id ID
     * @return 修改结果
     */
    JsonVO<Boolean> modifyStatus(@NotBlank(message = "id 不能为空") String id);
}
