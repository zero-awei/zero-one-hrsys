package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.mapper.WorkStatusMapper;
import com.zeroone.star.common.service.WorkStatusService;
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
public class WorkStatusServiceImpl implements WorkStatusService {

    @Resource
    private WorkStatusMapper workStatusMapper;

    @Override
    public List<DropdownListOptionDTO> listWorkStatus() {
        return workStatusMapper.selectWorkStatus();
    }
}
