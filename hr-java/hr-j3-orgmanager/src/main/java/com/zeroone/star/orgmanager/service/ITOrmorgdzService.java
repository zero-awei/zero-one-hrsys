package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDto;

/**
 * <p>
 * 组织地址维护 服务类
 * </p>
 *
 * @author wutong
 * @since 2023-05-30
 */
public interface ITOrmorgdzService extends IService<TOrmorgdz> {
    boolean deleteOrgAddress(OrgAddressDto ids);
}
