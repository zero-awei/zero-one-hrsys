package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;


/**
 * <p>
 * 描述：TODO
 * </p>
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
     * 修改权限
     *
     * @param dto 修改权限
     * @return 结果状态
     */
    JsonVO<Boolean> modifyMenu(MenuDTO dto);

    /**
     * 删除权限
     *
     * @param dto 删除权限
     * @return 结果状态
     */
    JsonVO<Boolean> removeMenu(MenuDTO dto);
}
