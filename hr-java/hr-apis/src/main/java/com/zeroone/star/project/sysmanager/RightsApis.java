package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.RightsDTO;
import com.zeroone.star.project.query.sysmanager.RightsQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：权限管理API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */

public interface RightsApis {
    /**
     * 分页查询列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<RightsDTO>> queryAll(RightsQuery query);

    /**
     * 添加权限
     *
     * @param dto 权限对象
     * @return 新增权限唯一编号
     */
    JsonVO<String> addRights(RightsDTO dto);

    /**
     * 修改权限
     *
     * @param dto 修改权限
     * @return 修改后的权限
     */
    JsonVO<RightsDTO> modifyRights(RightsDTO dto);

    /**
     * 删除权限
     *
     * @param dto 删除权限
     * @return 删除权限的编号
     */
    JsonVO<String> removeRights(RightsDTO dto);
}
