package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.common.entity.TSrfcodelist;
import com.zeroone.star.common.mapper.MsSrfcodeitemMapper;
import com.zeroone.star.common.mapper.TSrfcodeitemMapper;
import com.zeroone.star.common.mapper.TSrfcodelistMapper;
import com.zeroone.star.common.service.CommonService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class CommonServiceImpl implements CommonService {

    @Resource
    private TSrfcodeitemMapper srfcodeitemMapper;

    @Resource
    private TSrfcodelistMapper srfcodelistMapper;

    @Resource
    private MsSrfcodeitemMapper msSrfcodeitemMapper;

    @Override
    public List<DropdownListOptionDTO> listDropdownList(String name) {
        LambdaQueryWrapper<TSrfcodelist> codelistWrapper = new LambdaQueryWrapper<>();
        codelistWrapper.select(TSrfcodelist::getCodelistid).eq(TSrfcodelist::getCodelistname, name);
        TSrfcodelist tSrfcodelist = srfcodelistMapper.selectOne(codelistWrapper);
        String codelistid = tSrfcodelist.getCodelistid();
        LambdaQueryWrapper<TSrfcodeitem> codeitemWrapper = new LambdaQueryWrapper<>();
        codeitemWrapper.select(TSrfcodeitem::getCodeitemname, TSrfcodeitem::getCodeitemvalue).eq(TSrfcodeitem::getCodelistid, codelistid);
        return msSrfcodeitemMapper.dos2DTOs(srfcodeitemMapper.selectList(codeitemWrapper));
    }
}
