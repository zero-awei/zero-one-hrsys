package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.Srforg;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;

import java.util.List;

/**
 * <p>
 * 组织机构 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
public interface ISrforgService extends IService<Srforg> {
    /**
     * @param :
     * @return List<String>：组织分布
     * @author 乐天
     * @description:查询组织信息和对应的组织人数
     * @date 2023/5/22 1:17
     */
    List<OrgDistributeDTO> listOrgDistribute();


    List<AgencyProjectStaffDTO> listAgencyProjectStaff();

}
