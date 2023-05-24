package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.mapper.MaritalStatusMapper;
import com.zeroone.star.common.service.MaritalStatusService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/24 10:25
 */
@Service
public class MaritalStatusServiceImpl implements MaritalStatusService {

    @Resource
    private MaritalStatusMapper maritalStatusMapper;

    @Override
    public List<DropdownListOptionDTO> listMaritalStatus() {
        return maritalStatusMapper.selectMatrialStatus();
    }
}
