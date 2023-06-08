package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.BloodType;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 血型 服务类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-29
 */
public interface IBloodTypeService extends IService<BloodType> {

    List<DropdownListOptionDTO> listBloodType();
}
