package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.BloodType;
import com.zeroone.star.common.mapper.BloodTypeMapper;
import com.zeroone.star.common.service.IBloodTypeService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 血型 服务实现类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-29
 */
@Service
public class BloodTypeServiceImpl extends ServiceImpl<BloodTypeMapper, BloodType> implements IBloodTypeService {

    @Resource
    private BloodTypeMapper mapper;

    @Override
    public List<DropdownListOptionDTO> listBloodType() {
        return mapper.selectBloodType();
    }
}
