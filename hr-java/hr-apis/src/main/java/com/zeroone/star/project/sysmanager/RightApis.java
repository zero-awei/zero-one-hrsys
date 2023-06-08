package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.constraints.NotBlank;

/**
 * 权限接口
 *
 * @author authoralankay
 */

public interface RightApis {
    /**
     * 分页查询列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<RightDTO>> queryAll(RightQuery query);

    /**
     * 模糊查询
     *
     * @param query 模糊查询条件
     * @return JsonVO<PageDTO < RightsDTO>>
     */
    JsonVO<PageDTO<RightDTO>> queryLike(CommentQuery query);

    /**
     * 添加权限
     *
     * @param dto 权限对象
     * @return 结果状态
     */
    JsonVO<Boolean> addRight(RightDTO dto);

    /**
     * 修改权限
     *
     * @param dto 修改权限
     * @return 结果状态
     */
    JsonVO<Boolean> modifyRight(RightDTO dto);

    /**
     * 删除权限
     *
     * @param id 删除权限
     * @return 结果状态
     */
    JsonVO<Boolean> removeRight(@NotBlank(message = "id 不能为空")String id);

    /**
     * 修改状态
     * @param id ID
     * @return 修改结果
     */
    JsonVO<Boolean> modifyStatus(@NotBlank(message = "id 不能为空") String id);
}
