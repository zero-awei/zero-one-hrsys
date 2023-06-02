package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.Srforg;
import com.zeroone.star.dashboard.mapper.SrforgMapper;
import com.zeroone.star.dashboard.service.ISrforgService;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 组织机构 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
public class SrforgServiceImpl extends ServiceImpl<SrforgMapper, Srforg> implements ISrforgService {
    @Resource
    private SrforgMapper srforgMapper;

    @Override
    public List<OrgDistributeDTO> listOrgDistribute() {
        return srforgMapper.selectOrgDistribute();
    }

    @Override
    public List<AgencyProjectStaffDTO> listAgencyProjectStaff() {
        return srforgMapper.selectAgencyProjectStaff();
    }
}
