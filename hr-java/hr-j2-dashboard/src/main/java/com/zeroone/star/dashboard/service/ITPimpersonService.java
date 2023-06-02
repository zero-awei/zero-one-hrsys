package com.zeroone.star.dashboard.service;

import com.zeroone.star.dashboard.entity.TPimperson;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.dashboard.OrgPersonCountDTO;

import java.util.List;

/**
 * <p>
 * 人员信息 服务类
 * </p>
 *
 * @author letian
 * @since 2023-06-02
 */
public interface ITPimpersonService extends IService<TPimperson> {

    List<OrgPersonCountDTO> listOrgPersonCount();
}
