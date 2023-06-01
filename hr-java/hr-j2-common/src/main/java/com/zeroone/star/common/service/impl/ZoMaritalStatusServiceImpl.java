package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.ZoMaritalStatus;
import com.zeroone.star.common.mapper.ZoMaritalStatusMapper;
import com.zeroone.star.common.service.IZoMaritalStatusService;
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
public class ZoMaritalStatusServiceImpl extends ServiceImpl<ZoMaritalStatusMapper, ZoMaritalStatus> implements IZoMaritalStatusService {

    @Resource
    private ZoMaritalStatusMapper maritalStatusMapper;

    @Override
    public List<DropdownListOptionDTO> listMaritalStatus() {
        return maritalStatusMapper.selectMatrialStatus();
    }
}
