package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.StaffingControl;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 编制控制 服务类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-25
 */
public interface IStaffingControlService extends IService<StaffingControl> {

    List<DropdownListOptionDTO> listStaffingControl();
}
