package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.common.mapper.TSrfcodeitemMapper;
import com.zeroone.star.common.service.ITSrfcodeitemService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 代码项 服务实现类
 * </p>
 *
 * @author H
 * @since 2023-05-28
 */
@Service
public class TSrfcodeitemServiceImpl extends ServiceImpl<TSrfcodeitemMapper, TSrfcodeitem> implements ITSrfcodeitemService {
    @Autowired
    private TSrfcodeitemMapper mapper;

    @Override
    public List<DropdownListOptionDTO> listDistributionStatus() {
        return mapper.selectDistributionStatus();
    }


}
