package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

/**
 * <p>
 * 描述：权限管理API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */

public interface RightApis {
    /**
     * 分页查询列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<RightDTO>> queryAll(RightQuery query);

    /**
     * 添加权限
     *
     * @param dto 权限对象
     * @return 结果状态
     */
    JsonVO<ResultStatus> addRight(RightDTO dto);

    /**
     * 修改权限
     *
     * @param dto 修改权限
     * @return 结果状态
     */
    JsonVO<ResultStatus> modifyRight(RightDTO dto);

    /**
     * 删除权限
     *
     * @param dto 删除权限
     * @return 结果状态
     */
    JsonVO<ResultStatus> removeRight(RightDTO dto);
}
