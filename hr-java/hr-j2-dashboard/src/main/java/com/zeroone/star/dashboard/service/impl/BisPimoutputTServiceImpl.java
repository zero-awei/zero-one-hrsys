package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.BisPimoutputT;
import com.zeroone.star.dashboard.mapper.BisPimoutputTMapper;
import com.zeroone.star.dashboard.service.IBisPimoutputTService;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author wxs
 * @since 2023-06-01
 */
@Service
public class BisPimoutputTServiceImpl extends ServiceImpl<BisPimoutputTMapper, BisPimoutputT> implements IBisPimoutputTService {

    @Resource
    BisPimoutputTMapper bisPimoutputTMapper;

    @Override
    public List<PimOutputDTO> listMonthOutput() {
        return bisPimoutputTMapper.selectMonthOutput();
    }
}
