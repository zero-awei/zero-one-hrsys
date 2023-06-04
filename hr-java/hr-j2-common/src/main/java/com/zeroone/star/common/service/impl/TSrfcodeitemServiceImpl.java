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
        List<DropdownListOptionDTO> dtos = msSrfcodeitemMapper.dos2DTOs(baseMapper.selectList(wrapper));
        System.out.println(dtos);
        return dtos;
    }
}
