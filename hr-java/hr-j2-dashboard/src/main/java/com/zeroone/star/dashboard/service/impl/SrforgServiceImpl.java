package com.zeroone.star.dashboard.service.impl;

import com.zeroone.star.dashboard.entity.Srforg;
import com.zeroone.star.dashboard.mapper.SrforgMapper;
import com.zeroone.star.dashboard.service.ISrforgService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;
import org.springframework.stereotype.Service;

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

    private SrforgMapper srforgMapper;
    @Override
    public List<OrgDistributeDTO> getAllOrg() {
        return srforgMapper.selectAllOrg();
    }

    @Override
    public List<OrgEmployeeCountDTO> getOrgCount() {
        return srforgMapper.selectOrgEmployeeCount();
    }
}
