package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.project.vo.sysmanager.RightTreeVO;
import com.zeroone.star.sysmanager.entity.Right;
import com.zeroone.star.sysmanager.service.impl.RightServiceImpl;

import java.util.List;

/**
 * The service interface for {@link Right}, base on {@link IService}
 *
 * @author authoralankay
 * @see IService
 * @see RightServiceImpl
 */
public interface RightService extends IService<Right> {

    /**
     * 分页查询
     *
     * @param query {@link RightQuery}
     * @return 分页查询结果
     */
    JsonVO<PageDTO<RightDTO>> queryAll(RightQuery query);

    /**
     * 模糊查询
     *
     * @param query {@link CommentQuery}
     * @return 模糊查询结果
     */
    JsonVO<PageDTO<RightDTO>> queryLike(CommentQuery query);

    /**
     * 添加权限
     *
     * @param dto {@link RightDTO}
     * @return 添加权限是否成功
     */
    JsonVO<Boolean> addRight(RightDTO dto);

    /**
     * 修改权限
     *
     * @param dto {@link RightDTO}
     * @return 修改权限是否成功
     */
    JsonVO<Boolean> modifyRight(RightDTO dto);

    /**
     * 删除权限
     *
     * @param id 权限id
     * @return 删除权限结果
     */
    JsonVO<Boolean> removeRight(String id);

    /**
     * 修改权限状态
     *
     * @param id 权限id
     * @return 修改权限状态结果
     */
    JsonVO<Boolean> modifyStatus(String id);

    /**
     * 通过qu名称获取，权限资源
     * @param roleNames 角色名称
     * @return 返回权限列表
     */
    List<RightTreeVO> listRightByRoleName(List<String> roleNames);
}
