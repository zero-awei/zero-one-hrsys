package com.zeroone.star.dashboard.service.impl;

import com.zeroone.star.dashboard.entity.TPimperson;
import com.zeroone.star.dashboard.mapper.TPimpersonMapper;
import com.zeroone.star.dashboard.service.ITPimpersonService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.dashboard.AgeDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 人员信息 服务实现类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-29
 */
@Service
public class TPimpersonServiceImpl extends ServiceImpl<TPimpersonMapper, TPimperson> implements ITPimpersonService {

    @Resource
    private TPimpersonMapper mapper;

    @Override
    public List<AgeDTO> listAgeDistribution() {
        return mapper.selectAgeDistribution();
    }
}
