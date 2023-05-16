package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RightsDTO;
import com.zeroone.star.project.query.sysmanager.RightsQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @version 1.0.0
 */

public interface RightsApis {

    /**
     * <p>
     * 描述：分页查询列表
     * </p>
     *
     * @param query 查询条件
     * @return JsonVO<PageDTO < RightsDTO>>
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
