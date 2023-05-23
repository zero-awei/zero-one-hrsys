package com.zeroone.star.dashboard.service.impl;

import com.zeroone.star.dashboard.entity.BisEmployeeanalysis;
import com.zeroone.star.dashboard.mapper.BisEmployeeanalysisMapper;
import com.zeroone.star.dashboard.service.IBisEmployeeanalysisService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 员工基本信息分析表 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
public class BisEmployeeanalysisServiceImpl extends ServiceImpl<BisEmployeeanalysisMapper, BisEmployeeanalysis> implements IBisEmployeeanalysisService {
    @Resource
    private BisEmployeeanalysisMapper bisEmployeeanalysisMapper;
    @Override
    public List<OrgEmployeeCountDTO> getOrgCount() {
        return bisEmployeeanalysisMapper.selectOrgEmployeeCount();
    }
}
