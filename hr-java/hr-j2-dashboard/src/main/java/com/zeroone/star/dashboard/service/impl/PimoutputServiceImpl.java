package com.zeroone.star.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.dashboard.entity.Pimoutput;
import com.zeroone.star.dashboard.mapper.PimoutputMapper;
import com.zeroone.star.dashboard.service.IPimoutputService;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

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
    PimoutputMapper pimoutputMapper;

    @Override
    public List<PimOutputDTO> listYd() {
        return pimoutputMapper.selectYd();
    }
}