package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 代码项 服务类
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
public interface ITSrfcodeitemService extends IService<TSrfcodeitem> {

    List<DropdownListOptionDTO> listHouseHoldType();

    List<DropdownListOptionDTO> listEthnicType();

    List<DropdownListOptionDTO> listCityName();

    List<DropdownListOptionDTO> listBloodType();
}
