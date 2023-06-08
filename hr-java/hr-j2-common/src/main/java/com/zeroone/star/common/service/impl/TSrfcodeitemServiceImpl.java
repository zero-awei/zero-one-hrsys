package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.common.mapper.MsSrfcodeitemMapper;
import com.zeroone.star.common.mapper.TSrfcodeitemMapper;
import com.zeroone.star.common.service.ITSrfcodeitemService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 代码项 服务实现类
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
@Transactional
@Service
public class TSrfcodeitemServiceImpl extends ServiceImpl<TSrfcodeitemMapper, TSrfcodeitem> implements ITSrfcodeitemService {

    @Resource
    private MsSrfcodeitemMapper msSrfcodeitemMapper;

    @Override
    public List<DropdownListOptionDTO> listHouseHoldType() {
        LambdaQueryWrapper<TSrfcodeitem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(TSrfcodeitem::getCodelistid, "3F6DFE3C-1751-4696-AA60-6C63107437DE");
        return msSrfcodeitemMapper.dos2DTOs(baseMapper.selectList(wrapper));
    }

    @Override
    public List<DropdownListOptionDTO> listEthnicType() {
        LambdaQueryWrapper<TSrfcodeitem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(TSrfcodeitem::getCodelistid, "5CF8B6F8-0A7C-499E-80C6-DFD71151E537");
        return msSrfcodeitemMapper.dos2DTOs(baseMapper.selectList(wrapper));
    }

    @Override
    public List<DropdownListOptionDTO> listCityName() {
        LambdaQueryWrapper<TSrfcodeitem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(TSrfcodeitem::getCodelistid, "A7EED128-1F50-40A6-BD36-2CF2A90AEC6A");
        return msSrfcodeitemMapper.dos2DTOs(baseMapper.selectList(wrapper));
    }

    @Override
    public List<DropdownListOptionDTO> listBloodType() {
        LambdaQueryWrapper<TSrfcodeitem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(TSrfcodeitem::getCodelistid, "A7EED128-1F50-40A6-BD36-2CF2A90AEC6A");
        return msSrfcodeitemMapper.dos2DTOs(baseMapper.selectList(wrapper));
    }
}
