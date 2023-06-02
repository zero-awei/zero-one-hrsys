package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.TPimperson;
import com.zeroone.star.dashboard.mapper.TPimpersonMapper;
import com.zeroone.star.dashboard.service.ITPimpersonService;
import com.zeroone.star.project.dto.dashboard.AgeDTO;
import com.zeroone.star.project.dto.dashboard.OrgPersonCountDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 人员信息 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-06-02
 */
@Service
public class TPimpersonServiceImpl extends ServiceImpl<TPimpersonMapper, TPimperson> implements ITPimpersonService {
    @Resource
    private TPimpersonMapper pimpersonMapper;

    @Override
    public List<OrgPersonCountDTO> listOrgPersonCount() {
        return pimpersonMapper.selectOrgPersonCount();
    }

    @Resource
    private TPimpersonMapper mapper;

    @Override
    public List<AgeDTO> listAgeDistribution() {
        return mapper.selectAgeDistribution();
    }
}
