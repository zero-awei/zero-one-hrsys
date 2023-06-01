package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.BisProfessoranalysis;
import com.zeroone.star.dashboard.mapper.BisProfessoranalysisMapper;
import com.zeroone.star.dashboard.service.IBisProfessoranalysisService;
import com.zeroone.star.project.dto.dashboard.PimTitleDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 职称信息表 服务实现类
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Service
public class BisProfessoranalysisServiceImpl extends ServiceImpl<BisProfessoranalysisMapper, BisProfessoranalysis> implements IBisProfessoranalysisService {

    @Resource
    BisProfessoranalysisMapper bisProfessoranalysisMapper;


    @Override
    public List<PimTitleDTO> listRank() {
        return bisProfessoranalysisMapper.selectRank();
    }
}
