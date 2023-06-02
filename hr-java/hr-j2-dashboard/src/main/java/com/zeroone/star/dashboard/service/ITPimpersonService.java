package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.TPimperson;
import com.zeroone.star.project.dto.dashboard.AgeDTO;
import com.zeroone.star.project.dto.dashboard.OrgPersonCountDTO;

import java.util.List;

/**
 * <p>
 * 人员信息 服务类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-29
 */
public interface ITPimpersonService extends IService<TPimperson> {

    List<AgeDTO> listAgeDistribution();

    List<OrgPersonCountDTO> listOrgPersonCount();
}
