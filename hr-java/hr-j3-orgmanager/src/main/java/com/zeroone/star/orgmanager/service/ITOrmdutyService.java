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

    boolean updateByOrmdutyId(TOrmduty tOrmduty);

}
