package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.dashboard.entity.Pimoutput;
import com.zeroone.star.dashboard.mapper.PimoutputMapper;
import com.zeroone.star.dashboard.service.IPimoutputService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 产值表 服务实现类
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */

@Mapper(componentModel = "spring")
interface MsPimOutputMapper {
    /**
     * sample do 转换 sample dto
     * @param pimoutput do对象
     * @return dto对象
     */
    PimOutputDTO pimOutputToPimOutputDto(Pimoutput pimoutput);
}



@Service
public class PimoutputServiceImpl extends ServiceImpl<PimoutputMapper, Pimoutput> implements IPimoutputService {

    @Resource
    MsPimOutputMapper msPimOutputMapper;

    @Override
    public List<PimOutputDTO> listPimOutput() {
        LambdaQueryWrapper<Pimoutput> queryWrapper = new LambdaQueryWrapper<>();
        List<Pimoutput> pimOutputs = baseMapper.selectList(queryWrapper);
        List<PimOutputDTO> pimOutputDTOS = null;
        for (Pimoutput p : pimOutputs){
            PimOutputDTO pimOutputDTO = msPimOutputMapper.pimOutputToPimOutputDto(p);
            pimOutputDTOS.add(pimOutputDTO);
        }
        return pimOutputDTOS;
    }
}
