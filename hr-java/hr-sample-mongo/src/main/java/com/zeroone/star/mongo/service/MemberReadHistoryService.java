package com.zeroone.star.mongo.service;

import com.zeroone.star.mongo.entity.MemberReadHistory;

import java.util.List;

/**
 * <p>
 * 描述：会员浏览记录管理Service
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface MemberReadHistoryService {
    /**
     * 生成浏览记录
     * @param memberReadHistory 记录数据对象
     * @return 返回操作结果
     */
    int save(MemberReadHistory memberReadHistory);

    /**
     * 批量删除浏览记录
     * @param ids 要删除的记录ID集合
     * @return 返回操作结果
     */
    int remove(List<String> ids);

    /**
     * 获取用户浏览历史记录
     * @param memberId 会员编号
     * @return 浏览记录结果
     */
    List<MemberReadHistory> list(Long memberId);
}
