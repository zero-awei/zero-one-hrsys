package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TSrforg;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;

/**
 * <p>
 * 组织机构 服务类
 * </p>
 *
 * @author lr
 * @since 2023-05-29
 */
public interface ITSrforgService extends IService<TSrforg> {

    /**
     * 添加组织信息
     * @param addOrgInfoDTO 添加组织信息类
     */
    void saveOryData(AddOrgInfoDTO addOrgInfoDTO);
}
