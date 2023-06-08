package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.ZoWorkStatus;
import com.zeroone.star.common.mapper.ZoWorkStatusMapper;
import com.zeroone.star.common.service.IZoWorkStatusService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/23 23:20
 */
@Service
public class ZoWorkStatusServiceImpl extends ServiceImpl<ZoWorkStatusMapper, ZoWorkStatus>  implements IZoWorkStatusService {

    @Resource
    private ZoWorkStatusMapper zoWorkStatusMapper;

    @Override
    public List<DropdownListOptionDTO> listWorkStatus() {
        return zoWorkStatusMapper.selectWorkStatus();
    }
}
