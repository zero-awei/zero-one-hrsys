package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.BisEmployeeanalysis;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;

import java.util.List;

/**
 * <p>
 * 员工基本信息分析表 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
public interface IBisEmployeeanalysisService extends IService<BisEmployeeanalysis> {

    List<AgencyProjectStaffDTO> listAgencyProjectStaff();
}
