package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 组织部门 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
public interface ISrforgsectorService extends IService<Srforgsector> {
    Boolean  removeDeptById(String id);
}
