package com.zeroone.star.dashboard.service;

import com.zeroone.star.dashboard.entity.BisEmployeeanalysis;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;

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
    /**
     * @param :
     * @return Integer：组织人数
     * @author 乐天
     * @description：获取组织人数
     * @date 2023/5/22 1:18
     */
    List<OrgEmployeeCountDTO> getOrgCount();

    List<AgencyProjectStaffDTO> listAgencyProjectStaff();
}
