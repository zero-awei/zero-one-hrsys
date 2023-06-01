package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.BisRegisterT;
import com.zeroone.star.dashboard.mapper.BisRegisterTMapper;
import com.zeroone.star.dashboard.service.IBisRegisterTService;
import com.zeroone.star.project.dto.dashboard.PimVocationalDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 执业职格信息表 服务实现类
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */
@Service
public class BisRegisterTServiceImpl extends ServiceImpl<BisRegisterTMapper, BisRegisterT> implements IBisRegisterTService {

    @Resource
    private BisRegisterTMapper bisRegisterTMapper;


    @Override
    public List<PimVocationalDTO> listVocational() {
        return bisRegisterTMapper.selectVocational();
    }
}
