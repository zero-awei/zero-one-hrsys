package com.zeroone.star.project.menumanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.query.sysmanager.menumanager.MenuQuery;
import com.zeroone.star.project.vo.JsonVO;


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
     * <p>
     * 描述：分页查询列表
     * </p>
     * @param query 查询条件
     * @return JsonVO<PageDTO<MenuDTO>>
     */
    JsonVO<PageDTO<MenuDTO>> queryAll(MenuQuery query);
}
