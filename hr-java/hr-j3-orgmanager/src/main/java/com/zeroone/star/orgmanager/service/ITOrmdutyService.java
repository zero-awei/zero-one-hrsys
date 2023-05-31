package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.TOrmduty;

import java.util.List;

/**
 * <p>
 * 职务管理 服务类
 * </p>
 *
 * @author loop
 * @since 2023-05-27
 */
public interface ITOrmdutyService extends IService<TOrmduty> {

    /**
     * 更新职务信息
     * @param tOrmduty
     * @return
     */
    boolean updateByOrmdutyId(TOrmduty tOrmduty);

    /**
     * 批量删除职务信息
     * @param ids
     * @return
     */
    boolean deleteByOrmdutyIds(List<String> ids);
}
