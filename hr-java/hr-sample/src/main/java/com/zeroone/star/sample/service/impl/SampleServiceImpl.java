package com.zeroone.star.sample.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.sample.entity.Sample;
import com.zeroone.star.sample.mapper.SampleMapper;
import com.zeroone.star.sample.service.ISampleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：Sample对应MpStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsSampleMapper {
    /**
     * sample do 转换 sample dto
     * @param sample do对象
     * @return dto对象
     */
    SampleDTO sampleToSampleDto(Sample sample);
}

/**
 * <p>
 * 服务实现类
 * </p>
 * @author awei
 * @since 2023-05-06
 */
@Service
public class SampleServiceImpl extends ServiceImpl<SampleMapper, Sample> implements ISampleService {

    @Resource
    MsSampleMapper msSampleMapper;

    @Override
    public PageDTO<SampleDTO> listAll(SampleQuery query) {
        // 构建分页对象
        Page<Sample> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<Sample> wrapper = new QueryWrapper<>();
        wrapper.like("name", query.getName());
        // 执行分页查询
        Page<Sample> pageResult = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(pageResult, sample -> msSampleMapper.sampleToSampleDto(sample));
    }

    @Override
    public SampleDTO getById(int id) {
        Sample sample = baseMapper.selectById(id);
        if (sample != null){
            return msSampleMapper.sampleToSampleDto(sample);
        }
        return null;
    }
}
