package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.StaffingControl;
import com.zeroone.star.common.mapper.StaffingControlMapper;
import com.zeroone.star.common.service.IStaffingControlService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 编制控制 服务实现类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-25
 */
@Service
public class StaffingControlServiceImpl extends ServiceImpl<StaffingControlMapper, StaffingControl> implements IStaffingControlService {

    @Resource
    private StaffingControlMapper mapper;

    @Override
    public List<DropdownListOptionDTO> listStaffingControl() {
        return mapper.listStaffingControl();
    }
}
