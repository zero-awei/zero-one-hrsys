package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.RightsDTO;
import com.zeroone.star.project.query.sysmanager.RightsQuery;
import com.zeroone.star.project.vo.JsonVO;


/**
 * 权限接口
 *
 * @author authoralankay
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
     * 模糊查询
     *
     * @param query 模糊查询条件
     * @return JsonVO<PageDTO < RightsDTO>>
     */
    JsonVO<PageDTO<RightsDTO>> queryAll(String query);

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
