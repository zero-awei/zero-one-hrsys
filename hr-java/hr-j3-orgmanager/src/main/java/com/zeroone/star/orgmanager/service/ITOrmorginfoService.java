package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.TOrmorginfo;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;

/**
 * <p>
 * 组织信息 服务类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
public interface ITOrmorginfoService extends IService<TOrmorginfo> {

    /**
     * 添加组织信息
     * @param addOrgInfoDTO 添加组织信息类
     */
    void saveOryData(AddOrgInfoDTO addOrgInfoDTO);
}
