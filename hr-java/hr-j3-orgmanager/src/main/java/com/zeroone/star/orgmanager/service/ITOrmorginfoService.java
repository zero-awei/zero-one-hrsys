package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TOrmorginfo;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 组织信息 服务类
 * </p>
 *
 * @author H
 * @since 2023-05-30
 */
public interface ITOrmorginfoService extends IService<TOrmorginfo> {
    boolean deleteOrg(List<String> orgIds);
}
