package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.TPimcity;
import com.zeroone.star.common.mapper.TPimcityMapper;
import com.zeroone.star.common.service.ITPimcityService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.query.common.DistrictNameQuery;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsPimcityMapper {
    @Mappings({
            @Mapping(target = "key", source = "pimcityid"),
            @Mapping(target = "value", source = "pimcityname")
    })
    DropdownListOptionDTO do2DTO(TPimcity pimcity);

    List<DropdownListOptionDTO> dos2DTOs(List<TPimcity> dos);
}


/**
 * <p>
 * 市 服务实现类
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
@Service
public class TPimcityServiceImpl extends ServiceImpl<TPimcityMapper, TPimcity> implements ITPimcityService {

    @Resource
    private MsPimcityMapper msPimcityMapper;

    @Override
    public List<DropdownListOptionDTO> listDistrictName(DistrictNameQuery query) {
        LambdaQueryWrapper<TPimcity> wrapper = new LambdaQueryWrapper<>();
        wrapper.like(TPimcity::getPimcityname, query.getCityName());
        return msPimcityMapper.dos2DTOs(baseMapper.selectList(wrapper));
    }
}
